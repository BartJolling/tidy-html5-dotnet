#include "Conversions.hpp"

using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
    const char* Conversions::StringToCharArray(System::String^ managedString) {
        return static_cast<const char*>(Marshal::StringToHGlobalAnsi(managedString).ToPointer());
    }
}
