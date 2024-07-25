#pragma once

#include "tidy.h"
#include "Conversions.hpp"

using namespace System;

namespace TidyHtml5Dotnet
{
    public ref class Options
    {
    private:
        TidyDoc _tidyDoc = nullptr;

    internal:
        Options(const TidyDoc tidyDoc);

    public:
        DECLARE_PROPERTY_BOOL(DecorateInferredUL, TidyDecorateInferredUL)
        DECLARE_PROPERTY_BOOL(EscapeCdata, TidyEscapeCdata)             
        DECLARE_PROPERTY_BOOL(HideComments, TidyHideComments)
        DECLARE_PROPERTY_BOOL(IndentCdata, TidyIndentCdata)        
        DECLARE_PROPERTY_BOOL(JoinClasses, TidyJoinClasses)
        DECLARE_PROPERTY_BOOL(JoinStyles, TidyJoinStyles)               
        DECLARE_PROPERTY_BOOL(MergeEmphasis, TidyMergeEmphasis)
        DECLARE_PROPERTY_BOOL(AllowNumericCharacterReferences, TidyNCR)
        DECLARE_PROPERTY_STRING(NewBlockLevelTags, TidyBlockTags)
        DECLARE_PROPERTY_STRING(NewEmptyTags, TidyEmptyTags)
        DECLARE_PROPERTY_STRING(NewInlineTags, TidyInlineTags)
        DECLARE_PROPERTY_STRING(NewPreTags, TidyPreTags)
        DECLARE_PROPERTY_BOOL(OmitOptionalTags, TidyOmitOptionalTags)        
        DECLARE_PROPERTY_BOOL(UseColorNames, TidyReplaceColor)
        DECLARE_PROPERTY_AUTOBOOL(OutputBodyOnly, TidyBodyOnly)
    };
}
