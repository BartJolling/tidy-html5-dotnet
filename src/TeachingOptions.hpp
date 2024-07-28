#pragma once

#include "tidy.h"
#include "Conversions.hpp"

using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#MarkupTeachHeader
	/// </summary>
	public ref class TeachingOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		TeachingOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};
		
		DECLARE_PROPERTY_TAGNAMES(NewBlockLevelTags, TidyBlockTags)
		DECLARE_PROPERTY_TAGNAMES(NewEmptyTags, TidyEmptyTags)
		DECLARE_PROPERTY_TAGNAMES(NewInlineTags, TidyInlineTags)
		DECLARE_PROPERTY_TAGNAMES(NewPreTags, TidyPreTags)
	};
}