#pragma once

#include "AccessibilityCheckLevels.hpp"
#include "Conversions.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#DiagnosticsHeader
	/// </summary>
	public ref class DiagnosticOptions
	{
    private:
        TidyDoc _tidyDoc = nullptr;

    internal:
        DiagnosticOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

    public:
        DECLARE_PROPERTY_ENUM(AccessibilityCheckLevels, AccessibilityCheckLevel, TidyAccessibilityCheckLevel)
		DECLARE_PROPERTY_BOOL(ForceOutput, TidyForceOutput)
		DECLARE_PROPERTY_BOOL(ShowMetaChange, TidyShowMetaChange)
		DECLARE_PROPERTY_BOOL(WarnProprietaryAttributes, TidyWarnPropAttrs)
	};
}