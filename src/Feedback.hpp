#pragma once

#include "tidy.h"

using namespace System;

namespace TidyHtml5Dotnet
{
	public ref class Feedback
	{
	private:
		TidyMessage _tmessage = nullptr;

		String^ _key;
		String^ _output;

	public:
		Feedback(TidyMessage tmessage);

		property String^ Key {
			String^ get();
		}

		property String^ Output {
			String^ get();
		}
	} ;
}