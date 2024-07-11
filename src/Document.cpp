using namespace System;
using namespace System::IO;

#include "Document.hpp"

namespace TidyHtml5Dotnet 
{
	Document::Document()
	{
		_tidyDoc = tidyCreate();
		_options = gcnew TidyHtml5Dotnet::Options(_tidyDoc);
		_diagnostics = gcnew TidyHtml5Dotnet::Diagnostics(_tidyDoc);
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