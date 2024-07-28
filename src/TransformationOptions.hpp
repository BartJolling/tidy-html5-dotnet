#pragma once

#include "tidy.h"
#include "Conversions.hpp"

using namespace System;

namespace TidyHtml5Dotnet
{
    /// <summary>
    /// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#MarkupXFormHeader
    /// </summary>
    public ref class TransformationOptions
    {
    private:
        TidyDoc _tidyDoc = nullptr;

    internal:
        TransformationOptions(const TidyDoc tidyDoc)
        {
            assert(tidyDoc);
            _tidyDoc = tidyDoc;
        };

    public:
        DECLARE_PROPERTY_BOOL(DecorateInferredUL, TidyDecorateInferredUL)
        DECLARE_PROPERTY_BOOL(EscapeCdata, TidyEscapeCdata)             
        DECLARE_PROPERTY_BOOL(HideComments, TidyHideComments)
        DECLARE_PROPERTY_BOOL(JoinClasses, TidyJoinClasses)
        DECLARE_PROPERTY_BOOL(JoinStyles, TidyJoinStyles)               
        DECLARE_PROPERTY_BOOL(MergeEmphasis, TidyMergeEmphasis)
        DECLARE_PROPERTY_BOOL(ReplaceColor, TidyReplaceColor)

        /*
        DECLARE_PROPERTY_BOOL(IndentCdata, TidyIndentCdata)
        DECLARE_PROPERTY_BOOL(AllowNumericCharacterReferences, TidyNCR)
        DECLARE_PROPERTY_BOOL(OmitOptionalTags, TidyOmitOptionalTags)        
        DECLARE_PROPERTY_BOOL(UseColorNames, TidyReplaceColor)
        DECLARE_PROPERTY_AUTOBOOL(OutputBodyOnly, TidyBodyOnly)
        */
    };
}
