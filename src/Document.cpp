using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"

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
		_htmlString = htmlString;
		_contentString = Conversions::StringToCharArray(htmlString);
		_fromString = true;
	};

	Document::Document(Stream^ stream) : Document()
	{
		_stream = stream;
	};

	Document::~Document()
	{
		if (_contentString != nullptr)
		{
			IntPtr contentIntPtr = IntPtr((void*)_contentString);
			Marshal::FreeHGlobal(contentIntPtr);
			_contentString = nullptr;
		}

		tidyRelease(_tidyDoc);
	}

	DocumentStatuses Document::ParseString()
	{
		auto status = tidyParseString(_tidyDoc, _contentString);
		return static_cast<DocumentStatuses>(status);
	}

	DocumentStatuses Document::CleanAndRepair()
	{
		if (this->_fromString)
		{
			auto previousEncoding = _encodingOptions->InputCharacterEncoding;
			_encodingOptions->InputCharacterEncoding = Encodings::Utf8;
			ParseString();
			_encodingOptions->InputCharacterEncoding = previousEncoding;
		}
		else
		{

		}

		//cleaned = true;
		auto status = tidyCleanAndRepair(_tidyDoc);
		return static_cast<DocumentStatuses>(status);
	}
}