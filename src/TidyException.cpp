#include "TidyException.hpp"

#include <cstring>
#include <cstdlib>

using namespace System;

// private functions
namespace
{
    String^ GetErrorMessage(int errorNumber)
    {
        char buffer[256];
        strerror_s(buffer, sizeof(buffer), abs(errorNumber));
        return gcnew String(buffer);
    }
}

namespace TidyHtml5Dotnet
{
    TidyException::TidyException(int errorNumber)
        : Exception(GetErrorMessage(errorNumber))
    {
        this->_errorNumber = errorNumber;
    }
}
