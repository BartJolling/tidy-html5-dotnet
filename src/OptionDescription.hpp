#pragma once

using namespace System;

namespace TidyHtml5Dotnet
{
    public ref class OptionDescription
    {
    public:
        OptionDescription(
            String^ name,
            String^ category,
            unsigned int categoryId,
            String^ type,
            String^ potentialValues,
            String^ currentValue,
            bool haveValues)
        {
            _name = name;
            _category = category;
            _categoryId = categoryId;
            _type = type;
            _potentialValues = potentialValues;
            _currentValue = currentValue;
            _haveValues = haveValues;
        }

        // Read-only properties
        property String^ Name
        {
            String^ get() { return _name; }
        }

        property String^ Category
        {
            String^ get() { return _category; }
        }

        property unsigned int CategoryId
        {
            unsigned int get() { return _categoryId; }
        }

        property String^ Type
        {
            String^ get() { return _type; }
        }

        property String^ Values
        {
            String^ get() { return _potentialValues; }
        }

        property String^ Default
        {
            String^ get() { return _currentValue; }
        }

        property bool HaveValues
        {
            bool get() { return _haveValues; }
        }

    private:
        String^ _name;
        String^ _category;
        unsigned int _categoryId;
        String^ _type;
        String^ _potentialValues;
        String^ _currentValue;
        bool _haveValues;
    };
}