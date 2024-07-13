#pragma once

#include "config.h"

using namespace System;

#define DECLARE_PROPERTY_BOOL(PROPERTY_NAME, TIDY_OPTION_ID) \
property Boolean PROPERTY_NAME \
{ \
    Boolean get() { return tidyOptGetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID); } \
    void set(Boolean value) { tidyOptSetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, (Bool)value); } \
}

#define DECLARE_PROPERTY_AUTOBOOL(PROPERTY_NAME, TIDY_OPTION_ID) \
property Nullable<Boolean> PROPERTY_NAME \
{ \
    Nullable<Boolean> get() \
    { \
        auto value = static_cast<TidyTriState>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); \
        return Conversions::TidyTriStateToNullableBoolean(value); \
    } \
    void set(Nullable<Boolean> value) \
    { \
        auto autobool = Conversions::NullableBooleanToTidyTriState(value); \
        tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, autobool); \
    } \
}

#define DECLARE_PROPERTY_STRING(PROPERTY_NAME, TIDY_OPTION_ID) \
property String^ PROPERTY_NAME \
{ \
    String^ get() { return gcnew String(tidyOptGetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(String^ value) { tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, Conversions::StringToCharArray(value)); } \
}

#define DECLARE_PROPERTY_SIGNED_INTEGER(PROPERTY_NAME, TIDY_OPTION_ID) \
property Int32 PROPERTY_NAME \
{ \
    Int32 get() { return static_cast<Int32>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(Int32 value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

#define DECLARE_PROPERTY_UNSINGED_INTEGER(PROPERTY_NAME, TIDY_OPTION_ID) \
property UInt32 PROPERTY_NAME \
{ \
    UInt32 get() { return static_cast<UInt32>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(UInt32 value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

#define DECLARE_PROPERTY_ENUM(ENUM_TYPE, PROPERTY_NAME, TIDY_OPTION_ID) \
property ENUM_TYPE PROPERTY_NAME \
{ \
    ENUM_TYPE get() { return static_cast<ENUM_TYPE>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(ENUM_TYPE value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

namespace TidyHtml5Dotnet
{
    ref class Conversions abstract sealed
    {
    public:
        /*
        * Managed --> Tidy
        */

        static ctmbstr StringToCharArray(String^ managedString);
        static TidyTriState NullableBooleanToTidyTriState(Nullable<Boolean> nullableBool);

        /*
        * Managed --> Tidy
        */

        static Nullable<Boolean> TidyTriStateToNullableBoolean(TidyTriState autobool);
    };
}