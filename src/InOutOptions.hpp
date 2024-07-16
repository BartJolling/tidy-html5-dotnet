#pragma once

#include "Conversions.hpp"
#include "DocTypeModes.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#DocumentIOHeader
	/// </summary>	
	public ref class InOutOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		InOutOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		DECLARE_PROPERTY_BOOL(AddMetaCharset, TidyMetaCharset)
		DECLARE_PROPERTY_BOOL(AddXmlDeclaration, TidyXmlDecl)
		DECLARE_PROPERTY_BOOL(AddXmlSpace, TidyXmlSpace)
		DECLARE_PROPERTY_ENUM(DocTypeModes, DocTypeMode, TidyDoctypeMode)
		DECLARE_PROPERTY_BOOL(InputXml, TidyXmlTags)
		DECLARE_PROPERTY_BOOL(OutputHtml, TidyHtmlOut)
		DECLARE_PROPERTY_BOOL(OutputXhtml, TidyXhtmlOut)
		DECLARE_PROPERTY_BOOL(OutputXml, TidyXmlOut)
	};
}