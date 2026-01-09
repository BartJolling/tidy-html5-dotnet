#pragma once

#include <tidy.h>

#include "Conversions.hpp"
#include "OptionDescription.hpp"

using namespace System;
using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
    private ref class DocumentOptionsView
    {
    public:
        // Accept the native document handle
        DocumentOptionsView(TidyDoc tidyDoc);
        
        // Enumerates and returns an immutable snapshot.
        IReadOnlyList<OptionDescription^>^ GetOptionDescriptions();

    private:
        TidyDoc _tidyDoc;

        OptionDescription^ GetOptionDescription(TidyOption topt);
        String^ ConfigCategoryId(TidyConfigCategory id);

        // Comparer for sorting.
        ref class NameComparer : IComparer<OptionDescription^>
        {
        public:
            virtual int Compare(OptionDescription^ a, OptionDescription^ b);
        };
    };
}
