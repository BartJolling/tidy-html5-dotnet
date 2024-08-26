using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"
#include "InputSource.hpp"
#include "TidyException.hpp"
#include "Tidy.hpp"

namespace TidyHtml5Dotnet
{
	static Bool TIDY_CALL NativeMessageCallback(TidyMessage tmessage)
	{
		auto tidyDoc = tidyGetMessageDoc(tmessage);
		Document^ document = Tidy::GetRegisteredDocument(tidyDoc);

		if (document->FeedbackMessagesCallback != nullptr)
		{
			auto feedbackMessage = gcnew FeedbackMessage(tmessage);
			document->FeedbackMessagesCallback(feedbackMessage);
			return no;
		}
		return yes;
	}

	Document::Document()
	{
		_tidyDoc = tidyCreate();

		Tidy::RegisterDocument(_tidyDoc, this);

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
		_contentString = Conversions::StringToCharArray(htmlString);
	};

	Document::Document(Stream^ stream) : Document()
	{
		_inputSource = gcnew InputSource(stream);
	};

	Document^ Document::FromString(String^ htmlString)
	{
		ArgumentNullException::ThrowIfNullOrWhiteSpace(htmlString, "htmlString");
		return gcnew Document(htmlString);
	}

	Document^ Document::FromFile(String^ filePath)
	{
		ArgumentNullException::ThrowIfNullOrWhiteSpace(filePath, "filePath");

		if (!File::Exists(filePath))
			throw gcnew FileNotFoundException("File not found.", filePath);

		return gcnew Document(gcnew FileStream(filePath, FileMode::Open));
	}

	Document^ Document::FromStream(Stream^ stream)
	{
		ArgumentNullException::ThrowIfNull(stream, "stream");

		if (!stream->CanRead)
			throw gcnew ArgumentException("Stream must be readable.");
		if (!stream->CanSeek)
			throw gcnew ArgumentException("Stream must be seekable.");

		return gcnew Document(stream);
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
		Tidy::UnregisterDocument(_tidyDoc);
		tidyRelease(_tidyDoc);
	}

	void Document::FeedbackMessagesCallback::set(Action<FeedbackMessage^>^ value) 
	{
		Bool succes = tidySetMessageCallback(_tidyDoc, value 
			? NativeMessageCallback
			: nullptr);

		if (succes == no) 
			throw gcnew InvalidOperationException("Failed to set message call back");
			
		_feedbackMessagesCallback = value; 
	}
	
	Action<FeedbackMessage^>^ Document::FeedbackMessagesCallback::get()
	{
		return _feedbackMessagesCallback;
	}

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
		else if(this->_inputSource != nullptr)
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
}