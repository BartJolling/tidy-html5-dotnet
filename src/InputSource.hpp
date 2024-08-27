#pragma once

#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class InputSource
	{
	public:
		InputSource(Stream^ stream);
		~InputSource();
		!InputSource();

	private:
		Stream^ _stream;
		TidyInputSource* _tidyInputSource;

		int GetByte(void* source);
		void UngetByte(void* source, byte byte);
		bool IsEOF(void* source);

		bool _disposed = false;

	public:
		property TidyInputSource* TidyInSource
		{
			TidyInputSource* get() { return _tidyInputSource; }
		};
	};
};
