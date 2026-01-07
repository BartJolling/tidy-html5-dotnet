#pragma once
#include <tidy.h>
#include <tidybuffio.h>
#include "Conversions.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace TidyHtml5Dotnet
{
    public ref class DocumentOptionInfo
    {
    public:
        DocumentOptionInfo(String^ name, String^ value, int id, String^ type)
        {
            _name = name;
            _value = value;
            _id = id;
            _type = type;
        }


        // Read-only properties
        property String^ Name { String^ get() { return _name; } }
        property String^ Value { String^ get() { return _value; } }
        property int     Id { int get() { return _id; } }       // tidy option id (for debugging / filtering)
        property String^ Type { String^ get() { return _type; } }   // "Boolean" | "Integer" | "String" (mapped from TidyOptionType)

    private:
        String^ _name;
        String^ _value;
        int     _id;
        String^ _type;
    };

    private ref class DocumentOptionsView
    {
    public:
        // Accept the native document handle from your wrapper.
        DocumentOptionsView(TidyDoc tidyDoc)
        {
            if (tidyDoc == nullptr)
                throw gcnew ArgumentNullException("tidyDoc");

            _tidyDoc = tidyDoc;
        }
        
        // Enumerates and returns an immutable snapshot.
        IReadOnlyList<DocumentOptionInfo^>^ GetOptionsValues()
        {
            auto list = gcnew List<DocumentOptionInfo^>();

            TidyIterator pos = tidyGetOptionList(_tidyDoc);
            while (pos)
            {
                TidyOption opt = tidyGetNextOption(_tidyDoc, &pos);
                list->Add(ToTidyOptionInfo(opt));
            }

            // Sort by Name (optional).
            list->Sort(gcnew NameComparer());
            return list->AsReadOnly();
        }

        // Convenience: get current value by option name.
        String^ GetValue(String^ name)
        {
            if (String::IsNullOrWhiteSpace(name))
                throw gcnew ArgumentNullException("name");

            // Iterate to find matching name once; for perf you can cache.
            TidyIterator pos = tidyGetOptionList(_tidyDoc);
            while (pos)
            {
                TidyOption opt = tidyGetNextOption(_tidyDoc, &pos);
                auto oname = Conversions::CharArrayToString(tidyOptGetName(opt));
                if (String::Equals(oname, name, StringComparison::OrdinalIgnoreCase))
                    return Conversions::CharArrayToString(tidyOptGetValue(_tidyDoc, tidyOptGetId(opt)));
            }
            return nullptr; // not found
        }

    private:
        TidyDoc _tidyDoc;

        // Re-uses your earlier “console GetOption” logic, simplified to return a managed DTO.
        DocumentOptionInfo^ ToTidyOptionInfo(TidyOption opt)
        {
            TidyOptionId   optId = tidyOptGetId(opt);
            TidyOptionType optTy = tidyOptGetType(opt);

            auto name = Conversions::CharArrayToString(tidyOptGetName(opt));
            auto type = Conversions::MapOptionType(optTy);
            String^ value = nullptr;

            // Encoding group special-case
            switch (optId)
            {
            case TidyCharEncoding:
            case TidyInCharEncoding:
            case TidyOutCharEncoding:
                type = "Encoding";
                value = Conversions::CharArrayToString(tidyOptGetEncName(_tidyDoc, optId));
                if (!value) value = "?";
                break;

            default:
                switch (optTy)
                {
                case TidyBoolean:
                    value = Conversions::CharArrayToString(tidyOptGetCurrPick(_tidyDoc, optId));
                    break;

                case TidyInteger:
                    if (tidyOptGetPickList(opt)) // enum-like
                    {
                        type = "Enum";
                        value = Conversions::CharArrayToString(tidyOptGetCurrPick(_tidyDoc, optId));
                    }
                    else
                    {
                        int ival = tidyOptGetInt(_tidyDoc, optId);
                        value = System::Int32(ival).ToString();
                    }
                    break;

                case TidyString:
                    value = Conversions::CharArrayToString(tidyOptGetValue(_tidyDoc, optId));
                    break;
                }
                break;
            }

            return gcnew DocumentOptionInfo(name, value, static_cast<int>(optId), type);
        }

        // Comparer for sorting.
        ref class NameComparer : IComparer<DocumentOptionInfo^>
        {
        public:
            virtual int Compare(DocumentOptionInfo^ a, DocumentOptionInfo^ b)
            {
                return String::Compare(a->Name, b->Name, StringComparison::Ordinal);
            }
        };
    };
}
