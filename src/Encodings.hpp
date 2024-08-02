#pragma once

#include "tidyenum.h"

namespace TidyHtml5Dotnet
{
	public enum class Encodings
	{
		Raw = TidyEncodingOptions::TidyEncRaw,
		Ascii = TidyEncodingOptions::TidyEncAscii,
		Latin0 = TidyEncodingOptions::TidyEncLatin0,
		Latin1 = TidyEncodingOptions::TidyEncLatin1,
		Utf8 = TidyEncodingOptions::TidyEncUtf8,
		Iso2022 = TidyEncodingOptions::TidyEncIso2022,
		MacRoman = TidyEncodingOptions::TidyEncMac,
		Win1252 = TidyEncodingOptions::TidyEncWin1252,
		Ibm858 = TidyEncodingOptions::TidyEncIbm858,
		Utf16LittleEndian = TidyEncodingOptions::TidyEncUtf16le,
		Utf16BigEndian = TidyEncodingOptions::TidyEncUtf16be,
		Utf16 = TidyEncodingOptions::TidyEncUtf16,
		Big5 = TidyEncodingOptions::TidyEncBig5,
		ShiftJIS = TidyEncodingOptions::TidyEncShiftjis
	};
}