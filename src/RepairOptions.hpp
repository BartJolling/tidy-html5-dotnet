#pragma once

#include "Conversions.hpp"
#include "RepeatedAttributeModes.hpp"
#include "UseCustomTagsStates.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_next/tidy_quickref.html#MarkupRepairHeader
	/// </summary>
	public ref class RepairOptions
	{
    private:
        TidyDoc _tidyDoc = nullptr;

    internal:
        RepairOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

    public:
        DECLARE_PROPERTY_STRING(DefaultAltText, TidyAltText)
        DECLARE_PROPERTY_BOOL(AnchorAsName, TidyAnchorAsName)
        DECLARE_PROPERTY_BOOL(ChangeXmlProcessingInstructions, TidyXmlPIs)
		DECLARE_PROPERTY_BOOL(CoerceEndTags, TidyCoerceEndTags)
        DECLARE_PROPERTY_STRING(CssPrefix, TidyCSSPrefix)
        DECLARE_PROPERTY_ENUM(UseCustomTagsStates, UseCustomTags, TidyUseCustomTags)
        DECLARE_PROPERTY_BOOL(EncloseBlockText, TidyEncloseBlockText)
        DECLARE_PROPERTY_BOOL(EncloseBodyText, TidyEncloseBodyText)
        DECLARE_PROPERTY_BOOL(EscapeScripts, TidyEscapeScripts)
        DECLARE_PROPERTY_BOOL(FixUrlBackslashes, TidyFixBackslash)
        DECLARE_PROPERTY_AUTOBOOL(FixBadComments, TidyFixComments)
        DECLARE_PROPERTY_BOOL(FixStyleTags, TidyStyleTags)
        DECLARE_PROPERTY_BOOL(FixAttributeUris, TidyFixUri)
        DECLARE_PROPERTY_BOOL(LiteralAttributes, TidyLiteralAttribs)
        DECLARE_PROPERTY_BOOL(LowerCaseLiterals, TidyLowerLiterals)
        DECLARE_PROPERTY_ENUM(RepeatedAttributeModes, RepeatedAttributeMode, TidyDuplicateAttrs)
        DECLARE_PROPERTY_BOOL(SkipNestedTags, TidySkipNested)
        DECLARE_PROPERTY_BOOL(StrictTagsAttributes, TidyStrictTagsAttr)
        DECLARE_PROPERTY_BOOL(UpperCaseAttributes, TidyUpperCaseAttrs)
        DECLARE_PROPERTY_BOOL(UpperCaseTags, TidyUpperCaseTags)
	};
}