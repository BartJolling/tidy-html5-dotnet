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
	private delegate Bool FeedbackMessageDelegate(TidyMessage tmessage);

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

		//Dispose managed objects here
		delete _inputSource;

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

	void Document::FeedbackMessagesCallback::set(Action<FeedbackMessage^>^ value)
	{
		Bool succes = no;

		if (value)
		{
			auto feedbackDelegate = gcnew FeedbackMessageDelegate(this, &Document::FeedbackMessageCallback);
			auto feedbackPointer = Marshal::GetFunctionPointerForDelegate(feedbackDelegate).ToPointer();
			succes = tidySetMessageCallback(_tidyDoc, static_cast<TidyMessageCallback>(feedbackPointer));
		}
		else
		{
			succes = tidySetMessageCallback(_tidyDoc, nullptr);
		}

		if (succes == no)
			throw gcnew InvalidOperationException("Failed to set feedback message callback");

		_feedbackMessagesCallback = value;
	}

	Action<FeedbackMessage^>^ Document::FeedbackMessagesCallback::get()
	{
		return _feedbackMessagesCallback;
	}

	/// <summary>
	/// Parses input markup, and executes configured cleanup and repair operations.
	/// </summary>
	/// <returns>See Tidy error code convention (DocumentStatuses)</returns>
	DocumentStatuses Document::CleanAndRepair()
	{
		if (this->_contentString != nullptr)
		{
			auto previousEncoding = _encodingOptions->InputCharacterEncoding;
			_encodingOptions->InputCharacterEncoding = Encodings::Utf8;
			auto result = tidyParseString(_tidyDoc, _contentString);
			_encodingOptions->InputCharacterEncoding = previousEncoding;

			if (result < 0) throw gcnew TidyException(result);
			return static_cast<DocumentStatuses>(result);
		}
		else if (this->_inputSource != nullptr)
		{
			auto result = tidyParseSource(_tidyDoc, _inputSource->TidyInSource);

			if (result < 0) throw gcnew TidyException(result);
			return static_cast<DocumentStatuses>(result);
		}

		auto result = tidyCleanAndRepair(_tidyDoc);
		if (result < 0) throw gcnew TidyException(result);

		_cleaned = true;
		return static_cast<DocumentStatuses>(result);
	}


   // Override ToString method
    String^ Document::ToString()
    {
		int status = 0;
		tmbstr buffer = nullptr;
		uint outputLength = _inputLength * 2u; // Foresee enough initial room for cleaned output

		auto previousEncoding = _encodingOptions->OutputCharacterEncoding;		

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
}