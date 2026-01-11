#pragma once

#include "tidy.h"

namespace TidyHtml5Dotnet
{
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
}