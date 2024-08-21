using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"
#include "InputSource.hpp"
#include "TidyException.hpp"

namespace TidyHtml5Dotnet
{
	Bool TIDY_CALL NativeReportCallback(TidyMessage tmessage)
	{
    	Document::ReportCallback(tmessage);
		return no;
	}

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
		tidyRelease(_tidyDoc);
	}

	void Document::ReportCallback(TidyMessage tmessage)
	{
		if (_messageCallback != nullptr)
		{
			auto key = tidyGetMessageKey( tmessage );
			auto output = tidyGetMessageOutput( tmessage );			
			auto message = gcnew String(output);

			_messageCallback(message);
		}

		/* Move to a managed Message Class*/
		/*
		TidyIterator pos;
		TidyMessageArgument arg;
		TidyFormatParameterType messageType;
		ctmbstr messageFormat;

		printf("FILTER: %s, %s\n", tidyGetMessageKey( tmessage ), tidyGetMessageOutput( tmessage ));
		
		// loop through the arguments, if any, and print their details 
		pos = tidyGetMessageArguments( tmessage );
		while ( pos )
		{
			arg = tidyGetNextMessageArgument( tmessage, &pos );
			messageType = tidyGetArgType( tmessage, &arg );
			messageFormat = tidyGetArgFormat( tmessage, &arg );
			printf( "  Type = %u, Format = %s, Value = ", messageType, messageFormat );
			
			switch (messageType)
			{
				case tidyFormatType_STRING:
					printf("%s\n", tidyGetArgValueString( tmessage, &arg ));
					break;
					
				case tidyFormatType_INT:
					printf("%d\n", tidyGetArgValueInt( tmessage, &arg));
					break;
		
				case tidyFormatType_UINT:
					printf("%u\n", tidyGetArgValueUInt( tmessage, &arg));
					break;

				case tidyFormatType_DOUBLE:
					printf("%g\n", tidyGetArgValueDouble( tmessage, &arg));
					break;

				default:
					printf("%s", "unknown so far\n");
			}
		}
		*/
	}

	void Document::SetCallback(Action<String^>^ messageCallback)
	{
		_messageCallback = messageCallback;
		tidySetMessageCallback(_tidyDoc, NativeReportCallback);
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