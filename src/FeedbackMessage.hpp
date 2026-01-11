#pragma once

#include "tidy.h"
#include "ReportLevel.hpp"

using namespace System;
using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
	public ref class FeedbackMessage
	{
	private:
		String^ _key;
		String^ _output;
		List<String^>^ _arguments;
		ReportLevel _level;

	public:
		FeedbackMessage(TidyMessage tmessage);

		property String^ Key {
			String^ get();
		}

		property String^ Output {
			String^ get();
		}

		property ReportLevel Level {
			ReportLevel get();
		}

		property IEnumerable<String^>^ Arguments {
			 IEnumerable<String^>^ get();
		}

		virtual String^ ToString() override;
	};
}