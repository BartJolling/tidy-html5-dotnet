#pragma once

using namespace System;

namespace TidyHtml5Dotnet
{
	public ref class TidyException : Exception
	{
	public:
		TidyException(int errorNumber);
		
		property int ErrorNumber
		{
			int get() { return _errorNumber; }
		}

	private:
		int _errorNumber;
	};
}

