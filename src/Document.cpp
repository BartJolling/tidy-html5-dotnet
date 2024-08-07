using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

#include "Document.hpp"
#include "InputSource.hpp"
#include "TidyException.hpp"

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
		_contentString = Conversions::StringToCharArray(htmlString);
	};

	Document::Document(Stream^ stream) : Document()
	{
		_inputSource = gcnew InputSource(stream);
	};

	Document::~Document()
	{
		Conversions::FreeCharArray(_contentString);
		tidyRelease(_tidyDoc);
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