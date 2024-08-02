#pragma once

#include "Conversions.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#MarkupEntitiesHeader
	/// </summary>
	public ref class EntitiesOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		EntitiesOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		// [ascii - chars] Gets or sets whether & amp; emdash; , & amp; rdquo; , and other named character entities are downgraded to their closest ascii equivalents when the "MakeClean" option is set to true. Defaults to false.
		DECLARE_PROPERTY_BOOL(AsciiChars, TidyAsciiChars)

		// [ncr] Gets or sets whether Tidy should allow numeric character references. Defaults to true.
		DECLARE_PROPERTY_BOOL(NumericCharacterReferences, TidyNCR)
		
		// [numeric-entities] Gets or sets whether Tidy should output entities other than the built-in HTML entities (&amp;amp;, &amp;lt;, &amp;gt; and &amp;quot;) in the numeric rather than the named entity form. Only entities compatible with the DOCTYPE declaration generated are used. Entities that can be represented in the output encoding are translated correspondingly. Defaults to false.
		DECLARE_PROPERTY_BOOL(NumericEntities, TidyNumEntities)

		// [preserve - entities] Gets or sets whether Tidy should preserve the well - formed entitites as found in the input. Defaults to false.
		DECLARE_PROPERTY_BOOL(PreserveEntities, TidyPreserveEntities)

		// [quote-ampersand] Gets or sets whether Tidy should output unadorned &amp; characters as &amp;amp;. Defaults to true.
		DECLARE_PROPERTY_BOOL(QuoteAmpersands, TidyQuoteAmpersand)

		// [quote-marks] Gets or sets whether Tidy should output " characters as &amp;quot; as is preferred by some editing environments. The apostrophe character ' is written out as &amp;#39; since many web browsers don't yet support &amp;apos;. Defaults to false.
		DECLARE_PROPERTY_BOOL(QuoteMarks, TidyQuoteMarks)

		// [quote-nbsp] Gets or sets whether Tidy should output non-breaking space characters as entities, rather than as the Unicode character value 160 (decimal). Defaults to true.
		DECLARE_PROPERTY_BOOL(QuoteNonBreakingSpaces, TidyQuoteNbsp)
	};
}