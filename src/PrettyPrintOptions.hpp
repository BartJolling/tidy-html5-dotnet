#pragma once

#include "SortAttributeStrategy.hpp"
#include "Conversions.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#PrettyPrintHeader
	/// </summary>
	public ref class PrettyPrintOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		PrettyPrintOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		DECLARE_PROPERTY_BOOL(BreakBeforeBR, TidyBreakBeforeBR)
		DECLARE_PROPERTY_AUTOBOOL(IndentContent, TidyIndentContent)
		DECLARE_PROPERTY_BOOL(IndentAttributes, TidyIndentAttributes)
		DECLARE_PROPERTY_BOOL(IndentCData, TidyIndentCdata)
		DECLARE_PROPERTY_SIGNED_INTEGER(IndentSpaces, TidyIndentSpaces)
		DECLARE_PROPERTY_BOOL(IndentWithTabs, TidyPPrintTabs)		
		DECLARE_PROPERTY_BOOL(KeepTabs, TidyKeepTabs)
		DECLARE_PROPERTY_BOOL(OmitOptionalTags, TidyOmitOptionalTags)
		DECLARE_PROPERTY_TAGNAMES(PriorityAttributes, TidyPriorityAttributes)
		DECLARE_PROPERTY_BOOL(PunctuationWrap, TidyPunctWrap)
		DECLARE_PROPERTY_ENUM(SortAttributeStrategy, SortAttributes, TidySortAttributes)
		DECLARE_PROPERTY_SIGNED_INTEGER(TabSize, TidyTabSize)
		DECLARE_PROPERTY_BOOL(Mark, TidyMark)
		DECLARE_PROPERTY_AUTOBOOL(VerticalSpace, TidyVertSpace)
		DECLARE_PROPERTY_SIGNED_INTEGER(WrapLength, TidyWrapLen)
		DECLARE_PROPERTY_BOOL(WrapAsp, TidyWrapAsp)
		DECLARE_PROPERTY_BOOL(WrapAttributes, TidyWrapAttVals)
		DECLARE_PROPERTY_BOOL(WrapJste, TidyWrapJste)
		DECLARE_PROPERTY_BOOL(WrapPhp, TidyWrapPhp)
		DECLARE_PROPERTY_BOOL(WrapScriptLiterals, TidyWrapScriptlets)
		DECLARE_PROPERTY_BOOL(WrapSections, TidyWrapSection)
    };
}