#pragma once

namespace TidyHtml5Dotnet
{
	public enum class UseCustomTagsStates
	{
		No = 0,       /**< Do not allow autonomous custom tags */
		Blocklevel,   /**< ACT's treated as blocklevel */
		Empty,        /**< ACT's treated as empty tags */
		Inline,       /**< ACT's treated as inline tags */
		Pre           /**< ACT's treated as pre tags */
	};
}