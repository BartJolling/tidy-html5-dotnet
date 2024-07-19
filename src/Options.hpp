#pragma once

#include "tidy.h"
#include "Conversions.hpp"
#include "RepeatedAttributeModes.hpp"

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
        DECLARE_PROPERTY_STRING(DefaultAltText, TidyAltText)
        DECLARE_PROPERTY_BOOL(AnchorAsName, TidyAnchorAsName)
        DECLARE_PROPERTY_BOOL(ChangeXmlProcessingInstructions, TidyXmlPIs)
        DECLARE_PROPERTY_BOOL(CoerceEndTags, TidyCoerceEndTags)
        DECLARE_PROPERTY_STRING(CssPrefix, TidyCSSPrefix)
        DECLARE_PROPERTY_BOOL(DecorateInferredUL, TidyDecorateInferredUL)
        DECLARE_PROPERTY_BOOL(EncloseBlockText, TidyEncloseBlockText)
        DECLARE_PROPERTY_BOOL(EncloseBodyText, TidyEncloseBodyText)
        DECLARE_PROPERTY_BOOL(EscapeCdata, TidyEscapeCdata)
        DECLARE_PROPERTY_BOOL(FixUrlBackslashes, TidyFixBackslash)
        DECLARE_PROPERTY_BOOL(FixBadComments, TidyFixComments)
        DECLARE_PROPERTY_BOOL(FixAttributeUris, TidyFixUri)        
        DECLARE_PROPERTY_BOOL(HideComments, TidyHideComments)
        DECLARE_PROPERTY_BOOL(IndentCdata, TidyIndentCdata)        
        DECLARE_PROPERTY_BOOL(JoinClasses, TidyJoinClasses)
        DECLARE_PROPERTY_BOOL(JoinStyles, TidyJoinStyles)
        DECLARE_PROPERTY_BOOL(LiteralAttributes, TidyLiteralAttribs)        
        DECLARE_PROPERTY_BOOL(LowerCaseLiterals, TidyLowerLiterals)
        DECLARE_PROPERTY_BOOL(MergeEmphasis, TidyMergeEmphasis)
        DECLARE_PROPERTY_BOOL(AllowNumericCharacterReferences, TidyNCR)
        DECLARE_PROPERTY_STRING(NewBlockLevelTags, TidyBlockTags)
        DECLARE_PROPERTY_STRING(NewEmptyTags, TidyEmptyTags)
        DECLARE_PROPERTY_STRING(NewInlineTags, TidyInlineTags)
        DECLARE_PROPERTY_STRING(NewPreTags, TidyPreTags)
        DECLARE_PROPERTY_BOOL(OutputNumericEntities, TidyNumEntities)
        DECLARE_PROPERTY_BOOL(OmitOptionalTags, TidyOmitOptionalTags)
        DECLARE_PROPERTY_BOOL(PreserveEntities, TidyPreserveEntities)
        DECLARE_PROPERTY_BOOL(QuoteAmpersands, TidyQuoteAmpersand)
        DECLARE_PROPERTY_BOOL(QuoteMarks, TidyQuoteMarks)
        DECLARE_PROPERTY_BOOL(QuoteNonBreakingSpaces, TidyQuoteNbsp)
        DECLARE_PROPERTY_ENUM(RepeatedAttributeModes, RepeatedAttributeMode, TidyDuplicateAttrs)
        DECLARE_PROPERTY_BOOL(UseColorNames, TidyReplaceColor)
        DECLARE_PROPERTY_AUTOBOOL(OutputBodyOnly, TidyBodyOnly)
        DECLARE_PROPERTY_BOOL(SkipNestedTags, TidySkipNested)
        DECLARE_PROPERTY_BOOL(UpperCaseAttributes, TidyUpperCaseAttrs)
        DECLARE_PROPERTY_BOOL(UpperCaseTags, TidyUpperCaseTags)
    };
}
