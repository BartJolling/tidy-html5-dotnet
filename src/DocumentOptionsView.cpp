#include "DocumentOptionsView.hpp"
#include "OptionDescription.hpp"

using namespace System;
using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
    DocumentOptionsView::DocumentOptionsView(TidyDoc tidyDoc)
    {
        if (tidyDoc == nullptr)
            throw gcnew ArgumentNullException("tidyDoc");

        _tidyDoc = tidyDoc;
    }

    IReadOnlyList<OptionDescription^>^ DocumentOptionsView::GetOptionDescriptions()
    {
        auto list = gcnew List<OptionDescription^>();

        TidyIterator pos = tidyGetOptionList(_tidyDoc);
        while (pos)
        {
            TidyOption opt = tidyGetNextOption(_tidyDoc, &pos);
            list->Add(GetOptionDescription(opt));
        }

        // Sort by Name
        list->Sort(gcnew NameComparer());
        return list->AsReadOnly();
    }

    OptionDescription^ DocumentOptionsView::GetOptionDescription(TidyOption topt)
    {
        TidyOptionId   optId = tidyOptGetId(topt);
        TidyOptionType optTyp = tidyOptGetType(topt);

        String^ name = gcnew String(tidyOptGetName(topt));
        String^ category = gcnew String(ConfigCategoryId(tidyOptGetCategory(topt)));
        unsigned int categoryId = tidyOptGetCategory(topt);

        String^ type = nullptr;
        String^ potentialValues = nullptr;
        String^ currentValue = nullptr;
        bool haveValues = true;

        // Handle special cases first
        switch (optId)
        {
        case TidyInlineTags:
        case TidyBlockTags:
        case TidyCustomTags:
        case TidyEmptyTags:
        case TidyPreTags:
            type = "Tag Names";
            potentialValues = "tagX, tagY, ...";
            break;

        case TidyPriorityAttributes:
            type = "Attributes Names";
            potentialValues = "attributeX, attributeY, ...";
            break;

        case TidyCharEncoding:
        case TidyInCharEncoding:
        case TidyOutCharEncoding:
        {
            type = "Encoding";
            const char* enc = tidyOptGetEncName(_tidyDoc, optId);
            currentValue = enc ? gcnew String(enc) : "?";
            break;
        }

        // General case
        default:
            switch (optTyp)
            {
            case TidyBoolean:
                type = "Boolean";
                currentValue = gcnew String(tidyOptGetCurrPick(_tidyDoc, optId));
                break;

            case TidyInteger:
                if (tidyOptGetPickList(topt))
                {
                    type = "Enum";
                    currentValue = gcnew String(tidyOptGetCurrPick(_tidyDoc, optId));
                }
                else
                {
                    type = "Integer";

                    if (optId == TidyWrapLen)
                        potentialValues = "0 (no wrapping), 1, 2, ...";
                    else
                        potentialValues = "0, 1, 2, ...";

                    unsigned int idef = tidyOptGetInt(_tidyDoc, optId);
                    currentValue = idef.ToString();
                }
                break;

            case TidyString:
                type = "String";
                haveValues = false;
                currentValue = gcnew String(tidyOptGetValue(_tidyDoc, optId));
                break;
            }
            break;
        }

        return gcnew OptionDescription(
            name,
            category,
            categoryId,
            type,
            potentialValues,
            currentValue,
            haveValues
        );
    }

    String^ DocumentOptionsView::ConfigCategoryId(TidyConfigCategory id)
    {
        if (id >= TidyDiagnostics && id <= TidyInternalCategory)
        {
            auto key = tidyErrorCodeAsKey(id);
            return key ? gcnew String(key) : nullptr;
        }

        throw gcnew System::ArgumentOutOfRangeException(
            "id", 
            static_cast<int>(id),
            "Invalid Tidy configuration category."
        );
    }

    int DocumentOptionsView::NameComparer::Compare(OptionDescription^ a, OptionDescription^ b)
    {
        return String::Compare(a->Name, b->Name, StringComparison::Ordinal);
    }
}