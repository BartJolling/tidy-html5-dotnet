using namespace System;
using namespace System::IO;

#include "Document.hpp"

namespace TidyHtml5Dotnet 
{
	Document::Document()
	{
		_tidyDoc = tidyCreate();

		_options = gcnew TidyHtml5Dotnet::Options(_tidyDoc);
		_diagnosticOptions = gcnew TidyHtml5Dotnet::DiagnosticOptions(_tidyDoc);
		_displayOptions = gcnew TidyHtml5Dotnet::DisplayOptions(_tidyDoc);
		_inOutOptions = gcnew TidyHtml5Dotnet::InOutOptions(_tidyDoc);
		_fileOptions = gcnew TidyHtml5Dotnet::FileOptions(_tidyDoc);
	};

	Document::Document(String^ htmlString) : Document()
	{
		_htmlString = htmlString;
		_fromString = true;
	};

	Document::Document(Stream^ stream) : Document()
	{
		_stream = stream;
	};
}