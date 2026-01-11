using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"
#include "InputSource.hpp"
#include "OutputSink.hpp"
#include "TidyException.hpp"
#include "Tidy.hpp"

namespace TidyHtml5Dotnet
{
	Document::Document()
	{
		_tidyDoc = tidyCreate();

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
		_feedbackMessageDelegate = nullptr;  // Release delegate reference

		this->!Document();
		_disposed = true;
	}

	Document::!Document()
	{
		//Free unmanaged objects here
		Conversions::FreeCharArray(_contentString);
		tidyRelease(_tidyDoc);
	}

	/// <summary>
	/// Callback used by tidylib to return feedback messages
	/// </summary>
	/// <param name="tmessage">tidylib warning or error message</param>
	/// <returns>yes or no, indicating if tidylib should log to standard output or not</returns>
	Bool Document::FeedbackMessageCallback(TidyMessage tmessage)
	{
		if (FeedbackMessagesCallback != nullptr)
		{
			auto feedbackMessage = gcnew FeedbackMessage(tmessage);
			FeedbackMessagesCallback(feedbackMessage);
			return no;
		}
		return yes;
	}

	void Document::FeedbackMessagesCallback::set(Action<FeedbackMessage^>^ feedbackMessageHandler)
	{
	    Bool succes = no;

	    if (feedbackMessageHandler)
	    {
	        // Create delegate and keep it alive by storing in member variable
			_feedbackMessageDelegate = gcnew FeedbackMessageDelegate(this, &Document::FeedbackMessageCallback);
	        auto feedbackPointer = Marshal::GetFunctionPointerForDelegate(_feedbackMessageDelegate).ToPointer();
	        succes = tidySetMessageCallback(_tidyDoc, static_cast<TidyMessageCallback>(feedbackPointer));
	    }
	    else
	    {
	        succes = tidySetMessageCallback(_tidyDoc, nullptr);
			_feedbackMessageDelegate = nullptr;  // Allow GC to collect when unregistered
	    }

	    if (succes == no)
	        throw gcnew InvalidOperationException("Failed to set feedback message callback");

	    _feedbackMessagesCallback = feedbackMessageHandler;
	}

	Action<FeedbackMessage^>^ Document::FeedbackMessagesCallback::get()
	{
		return _feedbackMessagesCallback;
	}

    /// @brief Loads document config options from config file
    /// @param filePath Path to the config file
    /// @param encoding Encoding of the config file. If unspecified, assumes Ascii
    /// @return Error code indicating success or failure reading the file and setting the options
    DocumentStatuses Document::LoadConfig(String ^ filePath, Nullable<Encodings> encoding)
    {

		if (!encoding.HasValue) { encoding = Encodings::Ascii; }
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
    /// </summary>
    /// <returns>See Tidy error code convention (DocumentStatuses)</returns>
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
		delete [] buffer;

		_encodingOptions->OutputCharacterEncoding = previousEncoding;

		return output;
    }

    DocumentStatuses Document::ToStream(Stream ^ stream)
    {
		ArgumentNullException::ThrowIfNull(stream, "stream");

		if (!stream->CanWrite)
			throw gcnew ArgumentException("Stream must be writeable.");		

		auto result = tidySaveSink(_tidyDoc, (gcnew OutputSink(stream))->TidyOutSink);
		return static_cast<DocumentStatuses>(result);
    }

    DocumentStatuses Document::ToFile(String ^ filePath)
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