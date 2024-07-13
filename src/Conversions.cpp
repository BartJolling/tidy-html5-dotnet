#include "Conversions.hpp"

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

	TidyTriState Conversions::NullableBooleanToTidyTriState(Nullable<Boolean> nullableBool)
	{
		if (!nullableBool.HasValue) 
			return TidyTriState::TidyAutoState; // automatic

		return nullableBool.Value
			? TidyTriState::TidyYesState        // maps to 'true'
			: TidyTriState::TidyNoState;        // maps to 'false'
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
}