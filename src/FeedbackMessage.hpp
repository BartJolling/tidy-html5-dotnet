#pragma once

#include "tidy.h"

using namespace System;
using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
	public ref class FeedbackMessage
	{
	private:
		TidyMessage _tmessage = nullptr;

		String^ _key;
		String^ _output;
		List<String^>^ _arguments;

	public:
		FeedbackMessage(TidyMessage tmessage);

		property String^ Key {
			String^ get();
		}

		property String^ Output {
			String^ get();
		}

		property IEnumerable<String^>^ Arguments {
			 IEnumerable<String^>^ get();
		}

		virtual String^ ToString() override;
	};
}