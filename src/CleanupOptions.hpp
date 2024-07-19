#pragma once

#include "Conversions.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#MarkupCleanupHeader
	/// </summary>	
	public ref class CleanupOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		CleanupOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		DECLARE_PROPERTY_BOOL(MakeBare, TidyMakeBare)
		DECLARE_PROPERTY_BOOL(MakeClean, TidyMakeClean)
		DECLARE_PROPERTY_BOOL(DropEmptyElements, TidyDropEmptyElems)
		DECLARE_PROPERTY_BOOL(DropEmptyParagraphs, TidyDropEmptyParas)
		DECLARE_PROPERTY_BOOL(DropProprietaryAttributes, TidyDropPropAttrs)
		DECLARE_PROPERTY_BOOL(CleanGoogleDocs, TidyGDocClean)
		DECLARE_PROPERTY_BOOL(LogicalEmphasis, TidyLogicalEmphasis)
		DECLARE_PROPERTY_AUTOBOOL(MergeDivs, TidyMergeDivs)
		DECLARE_PROPERTY_AUTOBOOL(MergeSpans, TidyMergeSpans)
		DECLARE_PROPERTY_BOOL(CleanWord2000, TidyWord2000)
	};
}