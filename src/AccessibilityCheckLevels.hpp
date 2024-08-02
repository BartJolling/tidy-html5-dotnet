#pragma once

namespace TidyHtml5Dotnet
{
	public enum class AccessibilityCheckLevels
	{
		/// <summary>
		/// Equivalent to Tidy Classic's accessibility checking.
		/// </summary>
		TidyClassic = 0,
		/// <summary>
		/// Priority 1.
		/// </summary>
		Priority1 = 1,
		/// <summary>
		/// Priority 2.
		/// </summary>
		Priority2 = 2,
		/// <summary>
		/// Priority 3.
		/// </summary>
		Priority3 = 3
	};
}