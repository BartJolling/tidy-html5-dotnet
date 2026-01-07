#pragma once

#include "tidy.h"

using namespace System;
using namespace System::Collections::Generic;

namespace TidyHtml5Dotnet
{
	// TODO: move to its proper .hpp file
	public enum class ReportLevel
	{
		Info = TidyInfo,
		Warning = TidyWarning,
		Config = TidyConfig,
		Access = TidyAccess,
		Error = TidyError,
		BadDocument = TidyBadDocument,
		Fatal = TidyFatal,
		DialogueSummary = TidyDialogueSummary,
		DialogueInfo = TidyDialogueInfo,
		DialogueFootnote = TidyDialogueFootnote
	};

	public ref class FeedbackMessage
	{
	private:
		TidyMessage _tmessage = nullptr;

		String^ _key;
		String^ _output;
		List<String^>^ _arguments;
		int _level; // TODO: ReportLevel iso int

	public:
		FeedbackMessage(TidyMessage tmessage);

		property String^ Key {
			String^ get();
		}

		property String^ Output {
			String^ get();
		}

		property ReportLevel Level {  // Add this property
			ReportLevel get();
		}

		property IEnumerable<String^>^ Arguments {
			 IEnumerable<String^>^ get();
		}

		virtual String^ ToString() override;
	};
}