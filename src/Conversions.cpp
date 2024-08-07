#include "Conversions.hpp"
#include <sstream>

using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
	/*
	* Tidy --> Managed
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
	* Managed --> Tidy
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
}