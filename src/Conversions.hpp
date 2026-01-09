#pragma once

#include "config.h"

using namespace System;
using namespace System::Collections::Generic;

#define DECLARE_PROPERTY_BOOL(PROPERTY_NAME, TIDY_OPTION_ID) \
property Boolean PROPERTY_NAME \
{ \
    Boolean get() { return tidyOptGetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID); } \
    void set(Boolean value) { tidyOptSetBool(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, (Bool)value); } \
}

#define DECLARE_PROPERTY_AUTOBOOL(PROPERTY_NAME, TIDY_OPTION_ID) \
property Nullable<Boolean> PROPERTY_NAME \
{ \
    Nullable<Boolean> get() { return Conversions::TidyTriStateToNullableBoolean(static_cast<TidyTriState>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID))); } \
    void set(Nullable<Boolean> value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, Conversions::NullableBooleanToTidyTriState(value)); } \
}

#define DECLARE_PROPERTY_STRING(PROPERTY_NAME, TIDY_OPTION_ID) \
property String^ PROPERTY_NAME \
{ \
    String^ get() { return gcnew String(tidyOptGetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(String^ value) { \
        auto unmanagedValue = Conversions::StringToCharArray(value); \
        tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, unmanagedValue); \
        Conversions::FreeCharArray(unmanagedValue); \
    } \
}

#define DECLARE_PROPERTY_FILEINFO(PROPERTY_NAME, TIDY_OPTION_ID) \
property FileInfo^ PROPERTY_NAME \
{ \
    FileInfo^ get() \
    { \
        auto value = tidyOptGetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID); \
        return (value == nullptr || value[0] == '\0') ? nullptr : gcnew FileInfo(gcnew String(value)); \
    }; \
    void set(FileInfo^ value) { \
        if(value == nullptr) { tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, ""); } else { \
            auto unmanagedValue = Conversions::StringToCharArray(value->FullName); \
            tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, unmanagedValue ); \
            Conversions::FreeCharArray(unmanagedValue); } \
    }; \
}

#define DECLARE_PROPERTY_SIGNED_INTEGER(PROPERTY_NAME, TIDY_OPTION_ID) \
property Int32 PROPERTY_NAME \
{ \
    Int32 get() { return static_cast<Int32>(tidyOptGetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
    void set(Int32 value) { tidyOptSetInt(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, static_cast<ulong>(value)); } \
}

#define DECLARE_PROPERTY_UNSIGNED_INTEGER(PROPERTY_NAME, TIDY_OPTION_ID) \
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

#define DECLARE_PROPERTY_TAGNAMES(PROPERTY_NAME, TIDY_OPTION_ID) \
private: \
    IEnumerable<String^>^ PROPERTY_NAME##Cache = nullptr; \
public: \
    property IEnumerable<String^>^ PROPERTY_NAME { \
        IEnumerable<String^>^ get() { \
            if (PROPERTY_NAME##Cache == nullptr) { PROPERTY_NAME##Cache = Conversions::TidyTagNamesToIEnumerable(tidyOptGetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID)); } \
            return PROPERTY_NAME##Cache; \
        }; \
        void set(IEnumerable<String^>^ value) { \
            ArgumentNullException::ThrowIfNull(value, "value"); \
            if (tidyOptSetValue(_tidyDoc, TidyOptionId::TIDY_OPTION_ID, Conversions::IEnumerableToTidyTagNames(value))) { PROPERTY_NAME##Cache = nullptr; } \
        }; \
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
        static void FreeCharArray(ctmbstr unmanagedString);
		static TidyTriState NullableBooleanToTidyTriState(Nullable<Boolean> nullableBool);
        static ctmbstr Conversions::IEnumerableToTidyTagNames(IEnumerable<String^>^ tidyTagNames);

		/*
		* Tidy --> Managed
		*/

		static Nullable<Boolean> TidyTriStateToNullableBoolean(TidyTriState autobool);
        static IEnumerable<String^>^ TidyTagNamesToIEnumerable(ctmbstr tidyTagNames);
	};
}