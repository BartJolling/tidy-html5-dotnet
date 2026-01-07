#include "Conversions.hpp"
#include <sstream>

using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
	/*
	* Managed --> Tidy
	*/

	ctmbstr Conversions::StringToCharArray(String^ managedString)
	{
		return static_cast<const char*>(Marshal::StringToHGlobalAnsi(managedString).ToPointer());
	}

	void Conversions::FreeCharArray(ctmbstr unmanagedString)
	{
		if(unmanagedString) Marshal::FreeHGlobal(IntPtr((void*)unmanagedString));
	}

	TidyTriState Conversions::NullableBooleanToTidyTriState(Nullable<Boolean> nullableBool)
	{
		if (!nullableBool.HasValue)
			return TidyTriState::TidyAutoState; // automatic

		return nullableBool.Value
			? TidyTriState::TidyYesState        // maps to 'true'
			: TidyTriState::TidyNoState;        // maps to 'false'
	}

	ctmbstr Conversions::IEnumerableToTidyTagNames(IEnumerable<String^>^ tidyTagNames)
	{
		if (!Enumerable::Any(tidyTagNames)) { return ""; }
		auto joined = String::Join(",", tidyTagNames);
		return Conversions::StringToCharArray(joined);
	}

	/*
	* Tidy --> Managed
	*/

	Nullable<System::Boolean> Conversions::TidyTriStateToNullableBoolean(TidyTriState autobool)
	{
		switch (autobool)
		{
		case TidyTriState::TidyNoState:
			return Nullable<Boolean>(false);
		case TidyTriState::TidyYesState:
			return Nullable<Boolean>(true);
		default:
			return Nullable<Boolean>();
		}
	}

	IEnumerable<String^>^ Conversions::TidyTagNamesToIEnumerable(ctmbstr tidyTagNames)
	{
		if (tidyTagNames == nullptr) { return gcnew array<String^>(0); }

		List<String^>^ list = gcnew List<String^>();

		std::istringstream tagStream(tidyTagNames);
		std::string token;

		while (getline(tagStream, token, ','))
		{
			list->Add((gcnew String(token.c_str()))->TrimStart());
		}

		return list;
	}

	/// <summary>
	/// Convert ctmbstr (C string) to managed System::String^
	/// </summary>
	/// <param name="unmanagedString"></param>
	/// <returns></returns>
	String^ Conversions::CharArrayToString(ctmbstr unmanagedString)
	{
		//TODO: check if this cannot be done easier like gcnew String(unmanagedString)

		if (unmanagedString == nullptr) return nullptr;
		// ctmbstr is typically const char* (ANSI) in tidy builds.
		return gcnew String(reinterpret_cast<const char*>(unmanagedString));
	}

	/// <summary>
	/// Friendly name for TidyOptionType 
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	String^ Conversions::MapOptionType(TidyOptionType type)
	{
		//TODO : this does not belong here

		switch (type)
		{
		case TidyBoolean: return "Boolean";
		case TidyInteger: return "Integer";
		case TidyString:  return "String";
		default:          return "Unknown";
		}
	}
}