#pragma once

#include "tidy.h"
#include "Conversions.hpp"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#DisplayHeader
	/// </summary>	
	public ref class DisplayOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		DisplayOptions(const TidyDoc tidyDoc);

	public:
		DECLARE_PROPERTY_BOOL(GnuEmacs, TidyEmacs)
		DECLARE_PROPERTY_BOOL(Markup, TidyShowMarkup)
		DECLARE_PROPERTY_STRING(Mute, TidyMuteReports)   /**< Filter these messages from output. */
		DECLARE_PROPERTY_BOOL(MuteId, TidyMuteShow)      /**< Show message ID's in the error table */
		DECLARE_PROPERTY_BOOL(Quiet, TidyQuiet)
		DECLARE_PROPERTY_AUTOBOOL(ShowBodyOnly, TidyBodyOnly)
		DECLARE_PROPERTY_SIGNED_INTEGER(ShowErrors, TidyShowErrors)
		DECLARE_PROPERTY_BOOL(ShowFilename, TidyShowFilename)
		DECLARE_PROPERTY_BOOL(ShowInfo, TidyShowInfo)
		DECLARE_PROPERTY_BOOL(ShowWarnings, TidyShowWarnings)
	};
}