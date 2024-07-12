#pragma once

#include "tidy.h"
#include "AccessibilityCheckLevels.hpp"
#include "Conversions.hpp"

namespace TidyHtml5Dotnet
{
	public ref class Diagnostics
	{
    private:
        TidyDoc _tidyDoc = nullptr;

    internal:
        Diagnostics(const TidyDoc tidyDoc);

    public:
        DEFINE_PROPERTY_ENUM(AccessibilityCheckLevels, AccessibilityCheckLevel, TidyAccessibilityCheckLevel)
        DECLARE_PROPERTY_SIGNED_INTEGER(ShowErrors, TidyShowErrors)
        DECLARE_PROPERTY_BOOL(ShowInfo, TidyShowInfo)        
	};
}