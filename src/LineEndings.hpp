#pragma once

#include "tidyenum.h"

namespace TidyHtml5Dotnet
{
	public enum class LineEndings
	{
		LineFeed = TidyLineEnding::TidyLF,		            /**< Use Unix style: LF */
		CarriageReturnLineFeed = TidyLineEnding::TidyCRLF,  /**< Use DOS/Windows style: CR+LF */
		CarriageReturn = TidyLineEnding::TidyCR             /**< Use Macintosh style: CR */
	} ;
}