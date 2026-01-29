using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"
#include "InputSource.hpp"
#include "StreamSink.hpp"
#include "TidyException.hpp"
#include "Tidy.hpp"

namespace TidyHtml5Dotnet
{
	Document::Document()
	{
		_tidyDoc = tidyCreate();

		// Create delegate and keep it alive by storing in member variable
		_tidyMessageDelegate = gcnew TidyMessageDelegate(this, &Document::OnReceiveTidyMessage);
		auto feedbackPointer = Marshal::GetFunctionPointerForDelegate(_tidyMessageDelegate).ToPointer();
		if (tidySetMessageCallback(_tidyDoc, static_cast<TidyMessageCallback>(feedbackPointer)) == no)
		{
			throw gcnew InvalidOperationException("Failed to set tidy message callback");
		}

		// Options
		_cleanupOptions = gcnew TidyHtml5Dotnet::CleanupOptions(_tidyDoc);
		_diagnosticOptions = gcnew TidyHtml5Dotnet::DiagnosticOptions(_tidyDoc);
		_displayOptions = gcnew TidyHtml5Dotnet::DisplayOptions(_tidyDoc);
		_encodingOptions = gcnew TidyHtml5Dotnet::EncodingOptions(_tidyDoc);
		_entitiesOptions = gcnew TidyHtml5Dotnet::EntitiesOptions(_tidyDoc);
		_fileOptions = gcnew TidyHtml5Dotnet::FileOptions(_tidyDoc);
		_inOutOptions = gcnew TidyHtml5Dotnet::InOutOptions(_tidyDoc);
		_prettyPrintOptions = gcnew TidyHtml5Dotnet::PrettyPrintOptions(_tidyDoc);
		_repairOptions = gcnew TidyHtml5Dotnet::RepairOptions(_tidyDoc);
		_teachingOptions = gcnew TidyHtml5Dotnet::TeachingOptions(_tidyDoc);
		_transformationOptions = gcnew TidyHtml5Dotnet::TransformationOptions(_tidyDoc);
	};

	Document::Document(String^ htmlString) : Document()
	{
		ArgumentNullException::ThrowIfNullOrWhiteSpace(htmlString, "htmlString");

		_contentString = Conversions::StringToCharArray(htmlString);
		_inputLength = htmlString->Length;
	};

	Document::Document(Stream^ stream) : Document()
	{
		ArgumentNullException::ThrowIfNull(stream, "stream");

		if (!stream->CanRead)
			throw gcnew ArgumentException("Stream must be readable.");
		if (!stream->CanSeek)
			throw gcnew ArgumentException("Stream must be seekable.");

		_inputSource = gcnew InputSource(stream);
		_inputLength = stream->Length;
	};

	Document^ Document::FromString(String^ htmlString)
	{
		return gcnew Document(htmlString);
	}

	Document^ Document::FromStream(Stream^ stream)
	{
		return gcnew Document(stream);
	}

	Document^ Document::FromFile(String^ filePath)
	{
		ArgumentNullException::ThrowIfNullOrWhiteSpace(filePath, "filePath");

		if (!File::Exists(filePath))
			throw gcnew FileNotFoundException("File not found.", filePath);

		return gcnew Document(gcnew FileStream(filePath, FileMode::Open));
	}

	Document::~Document()
	{
		if (_disposed) return;

		delete _inputSource;
		delete _reportStreamSink;
		_tidyMessageDelegate = nullptr;  // Release delegate reference

		this->!Document();
		_disposed = true;
	}

	Document::!Document()
	{
		//Free unmanaged objects
		Conversions::FreeCharArray(_contentString);
		tidyRelease(_tidyDoc);
	}

	/// <summary>
	/// Callback used by tidylib to return feedback messages
	/// </summary>
	/// <param name="tmessage">tidylib warning or error message</param>
	/// <returns>yes or no, indicating if tidylib should log to the report stream or report file or not</returns>
	Bool Document::OnReceiveTidyMessage(TidyMessage tmessage)
	{
		auto feedbackMessage = gcnew FeedbackMessage(tmessage);

		IncludeInReport includeInReport = IncludeInReport::Yes;

		if (OnReceiveDiagnosticMessage != nullptr)
		{
			includeInReport = OnReceiveDiagnosticMessage(feedbackMessage);
		}

		if (includeInReport == IncludeInReport::Yes)
		{
			_diagnosticMessages->Add(feedbackMessage);
			return yes;
		}

		return no;
	}

	/// <summary>
	/// Loads document configuration options from a configuration file.
	/// </summary>
	/// <param name="filePath">
	/// Path to the configuration file.
	/// </param>
	/// <param name="encoding">
	/// Encoding of the configuration file. If not specified, ASCII is assumed.
	/// </param>
	/// <returns>
	/// A status code indicating success or failure when reading the file
	/// and applying the configuration options.
	/// </returns>
	DocumentStatuses Document::LoadConfig(String^ filePath, Nullable<Encodings> encoding)
	{
		encoding = encoding.GetValueOrDefault(Encodings::Ascii);

		String^ encodingName = Enum::GetName(Encodings::typeid, encoding);

		auto filePathC = Conversions::StringToCharArray(filePath);
		auto encodingC = Conversions::StringToCharArray(encodingName);

		int result = tidyLoadConfigEnc(_tidyDoc, filePathC, encodingC);

		Conversions::FreeCharArray(filePathC);
		Conversions::FreeCharArray(encodingC);

		return static_cast<DocumentStatuses>(result);
	}

	/// <summary>
	/// Parses input markup, and executes configured cleanup and repair operations.
	/// The diagnostic report is written to the provided report stream.
	/// </summary>
	/// <param name="reportStream">An open and writeable stream to write the report to</param>
	/// <returns>A status for success, with warnings or with errors</returns>
	DocumentStatuses Document::CleanAndRepair(Stream^ reportStream)
	{
		ArgumentNullException::ThrowIfNull(reportStream, "stream");

		if (!reportStream->CanWrite)
			throw gcnew ArgumentException("Stream must be writable.", "reportStream");

		_reportStreamSink = gcnew StreamSink(reportStream);

		int result = tidySetErrorSink(_tidyDoc, _reportStreamSink->TidyOutSink);
		if (result != 0)
			throw gcnew InvalidOperationException("Failed to set report stream.");

		return CleanAndRepair();
	}

	/// <summary>
	/// Parses input markup, and executes configured cleanup and repair operations.
	/// The diagnostic report is written to the provide report file.
	/// </summary>
	/// <param name="reportFilePath">An file path to writeable location to write the report to</param>
	/// <returns>A status for success, with warnings or with errors</returns>
	DocumentStatuses Document::CleanAndRepair(String^ reportFilePath)
	{
		ArgumentNullException::ThrowIfNullOrWhiteSpace(reportFilePath, "reportFilePath");

		FILE* f = tidySetErrorFile(
			_tidyDoc,
			Conversions::StringToCharArray(reportFilePath)
		);

		if (f == nullptr)
		{
			throw gcnew IOException(
				String::Format("Failed to open report file '{0}'.", reportFilePath));
		}

		return CleanAndRepair();
	}

	/// <summary>
	/// Parses input markup, and executes configured cleanup and repair operations.
	/// The diagnostic report is written to the stderr stream.
	/// </summary>
	/// <returns>A status for success, with warnings or with errors</returns>
	DocumentStatuses Document::CleanAndRepair()
	{
		int parseResult = 0;
		if (this->_contentString != nullptr)
		{
			auto previousEncoding = _encodingOptions->InputCharacterEncoding;
			_encodingOptions->InputCharacterEncoding = Encodings::Utf8;
			parseResult = tidyParseString(_tidyDoc, _contentString);
			_encodingOptions->InputCharacterEncoding = previousEncoding;

			if (parseResult < 0) throw gcnew TidyException(parseResult);
		}
		else if (this->_inputSource != nullptr)
		{
			parseResult = tidyParseSource(_tidyDoc, _inputSource->TidyInSource);

			if (parseResult < 0) throw gcnew TidyException(parseResult);
		}
		else
		{
			// Nothing to parse. Exit here because tidyRunDiagnostics crashes on empty doc
			return static_cast<DocumentStatuses>(parseResult);
		}

		try
		{
			// Run clean & repair after parsing
			auto repairResult = tidyCleanAndRepair(_tidyDoc);
			if (repairResult < 0) throw gcnew TidyException(repairResult);

			_cleaned = true;

			auto diagResults = tidyRunDiagnostics(_tidyDoc);
			if (diagResults < 0) throw gcnew TidyException(diagResults);

			/* generate footnote messages only if errors or warnings */
			if (ErrorCount + WarningCount > 0)
				ErrorSummary();

			return static_cast<DocumentStatuses>(repairResult);
		}
		finally
		{
			if (_reportStreamSink != nullptr)
			{
				delete _reportStreamSink;
				_reportStreamSink = nullptr;
			}

			// Reset to default stderr
			tidySetErrorFile(_tidyDoc, nullptr);
		}
	}

	DocumentStatuses Document::ReportDocType()
	{
		auto result = tidyReportDoctype(_tidyDoc);
		return static_cast<DocumentStatuses>(result);
	}

	DocumentStatuses Document::RunDiagnostics()
	{
		auto result = tidyRunDiagnostics(_tidyDoc);
		return static_cast<DocumentStatuses>(result);
	}

	void Document::ErrorSummary()
	{
		tidyErrorSummary(_tidyDoc);
	}

	void Document::GeneralInfo()
	{
		tidyGeneralInfo(_tidyDoc);
	}

	String^ Document::ToString()
	{
		int status = 0;
		tmbstr buffer = nullptr;
		uint outputLength = _inputLength * 2u; // Foresee enough initial room for cleaned output

		if (_inputLength > UINT_MAX / 2)
			return String::Empty; // Prevent overflow

		auto previousEncoding = _encodingOptions->OutputCharacterEncoding;

		// TODO: slow buffer increment +1. What if doc could give required length before hand
		do {
			buffer = new char[outputLength + 1];
			_encodingOptions->OutputCharacterEncoding = Encodings::Utf8;
			status = tidySaveString(_tidyDoc, buffer, &outputLength);
		} while (status == -ENOMEM);

		buffer[outputLength] = '\0';
		auto output = gcnew String(buffer);
		delete[] buffer;

		_encodingOptions->OutputCharacterEncoding = previousEncoding;

		return output;
	}

	DocumentStatuses Document::ToStream(Stream^ stream)
	{
		ArgumentNullException::ThrowIfNull(stream, "stream");

		if (!stream->CanWrite)
			throw gcnew ArgumentException("Stream must be writeable.");

		auto result = tidySaveSink(_tidyDoc, (gcnew StreamSink(stream))->TidyOutSink);
		return static_cast<DocumentStatuses>(result);
	}

	DocumentStatuses Document::ToFile(String^ filePath)
	{
		if (String::IsNullOrWhiteSpace(filePath))
			throw gcnew ArgumentNullException("filePath");

		auto result = tidySaveFile(_tidyDoc, Conversions::StringToCharArray(filePath));
		return static_cast<DocumentStatuses>(result);
	}

	uint Document::AccessWarningCount::get()
	{
		return tidyAccessWarningCount(_tidyDoc);
	}

	uint Document::ErrorCount::get()
	{
		return tidyErrorCount(_tidyDoc);
	}

	uint Document::WarningCount::get()
	{
		return tidyWarningCount(_tidyDoc);
	}

	IReadOnlyList<OptionDescription^>^ Document::GetOptionDescriptions()
	{
		auto view = gcnew DocumentOptionsView(_tidyDoc);
		return view->GetOptionDescriptions();
	}
}