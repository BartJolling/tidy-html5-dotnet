#pragma once

#include "tidy.h"
#include "DocTypeMode.hpp"
#include "TriState.hpp"

#define DECLARE_PROPERTY_BOOL(PROPERTY_NAME, TIDY_OPTION_ID) \
property Boolean PROPERTY_NAME \
{ \
    Boolean get() { return tidyOptGetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID); } \
    void set(Boolean value) { tidyOptSetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, (Bool)value); } \
}

#define DECLARE_PROPERTY_STRING(PROPERTY_NAME, TIDY_OPTION_ID) \
property String^ PROPERTY_NAME \
{ \
    String^ get() { return gcnew String(tidyOptGetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(String^ value) { tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, ConvertString(value)); } \
}

#define DECLARE_PROPERTY_INTEGER(PROPERTY_NAME, TIDY_OPTION_ID) \
property UInt32 PROPERTY_NAME \
{ \
    UInt32 get() { return static_cast<UInt32>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(UInt32 value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

#define DEFINE_PROPERTY_ENUM(ENUM_TYPE, PROPERTY_NAME, TIDY_OPTION_ID) \
property ENUM_TYPE PROPERTY_NAME \
{ \
    ENUM_TYPE get() { return static_cast<ENUM_TYPE>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(ENUM_TYPE value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

using namespace System;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet {
	public ref class Options
	{
	private:
		TidyDoc _tidyDoc = nullptr;

		ctmbstr ConvertString(System::String^ managedString) {
			return static_cast<ctmbstr>(Marshal::StringToHGlobalAnsi(managedString).ToPointer());
		}

	internal:
		Options(const TidyDoc tidyDoc);

	public:
		DECLARE_PROPERTY_BOOL(AddXmlDeclaration, TidyXmlDecl)
		DECLARE_PROPERTY_BOOL(AddXmlSpacePreserve, TidyXmlSpace)
		DECLARE_PROPERTY_STRING(DefaultAltText, TidyAltText)
		DECLARE_PROPERTY_BOOL(AnchorAsName, TidyAnchorAsName)
		DECLARE_PROPERTY_BOOL(ChangeXmlProcessingInstructions, TidyXmlPIs)
		DECLARE_PROPERTY_BOOL(MakeBare, TidyMakeBare)
		DECLARE_PROPERTY_BOOL(MakeClean, TidyMakeClean)
		DECLARE_PROPERTY_BOOL(CoerceEndTags, TidyCoerceEndTags)
		DECLARE_PROPERTY_STRING(CssPrefix, TidyCSSPrefix)
		DECLARE_PROPERTY_BOOL(DecorateInferredUL, TidyDecorateInferredUL)		
		DEFINE_PROPERTY_ENUM(DocTypeMode, DocType, TidyDoctypeMode)
		DECLARE_PROPERTY_BOOL(DropEmptyElements, TidyDropEmptyElems)
		DECLARE_PROPERTY_BOOL(DropEmptyParagraphs, TidyDropEmptyParas)
		DECLARE_PROPERTY_BOOL(DropProprietaryAttributes, TidyDropPropAttrs)
		DECLARE_PROPERTY_BOOL(EncloseBlockText, TidyEncloseBlockText)
		DECLARE_PROPERTY_BOOL(EncloseBodyText, TidyEncloseBodyText)
		DECLARE_PROPERTY_BOOL(EscapeCdata, TidyEscapeCdata)
		DECLARE_PROPERTY_BOOL(FixUrlBackslashes, TidyFixBackslash)
		DECLARE_PROPERTY_BOOL(FixBadComments, TidyFixComments)
		DECLARE_PROPERTY_BOOL(FixAttributeUris, TidyFixUri)
		DECLARE_PROPERTY_BOOL(CleanGoogleDocs, TidyGDocClean)
		DECLARE_PROPERTY_BOOL(HideComments, TidyHideComments)
		DECLARE_PROPERTY_BOOL(IndentCdata, TidyIndentCdata)
		DECLARE_PROPERTY_BOOL(InputXmlTags, TidyXmlTags)
		DECLARE_PROPERTY_BOOL(JoinClasses, TidyJoinClasses)
		DECLARE_PROPERTY_BOOL(JoinStyles, TidyJoinStyles)
		DECLARE_PROPERTY_BOOL(LiteralAttributes, TidyLiteralAttribs)
		DECLARE_PROPERTY_BOOL(LogicalEmphasis, TidyLogicalEmphasis)
		DECLARE_PROPERTY_BOOL(LowerCaseLiterals, TidyLowerLiterals)
		DEFINE_PROPERTY_ENUM(TriState, MergeDivs, TidyMergeDivs)
		DECLARE_PROPERTY_BOOL(MergeEmphasis, TidyMergeEmphasis)
		DEFINE_PROPERTY_ENUM(TriState, MergeSpans, TidyMergeSpans)
		DECLARE_PROPERTY_BOOL(AllowNumericCharacterReferences, TidyNCR)
		DECLARE_PROPERTY_STRING(NewBlockLevelTags, TidyBlockTags)
		DECLARE_PROPERTY_STRING(NewEmptyTags, TidyEmptyTags)
		DECLARE_PROPERTY_STRING(NewInlineTags, TidyInlineTags)
		DECLARE_PROPERTY_STRING(NewPreTags, TidyPreTags)
	};
}
