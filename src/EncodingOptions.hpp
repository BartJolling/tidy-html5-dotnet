#pragma once

#include "Conversions.hpp"
#include "Encodings.hpp"
#include "LineEndings.hpp"
#include "tidy.h"

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#EncodingHeader
	/// </summary>
	public ref class EncodingOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		EncodingOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		// [char-encoding] Gets or sets character encoding Tidy uses for both the input and output. For ascii, Tidy will accept Latin-1 (ISO-8859-1) character values, but will use entities for all characters whose value > 127. For raw, Tidy will output values above 127 without translating them into entities. For latin1, characters above 255 will be written as entities. For utf8, Tidy assumes that both input and output is encoded as UTF-8. You can use iso2022 for files encoded using the ISO-2022 family of encodings e.g. ISO-2022-JP. For mac and win1252, Tidy will accept vendor specific character values, but will use entities for all characters whose value > 127. For unsupported encodings, use an external utility to convert to and from UTF-8. Defaults to "utf8".
		DECLARE_PROPERTY_ENUM(Encodings, CharacterEncoding, TidyCharEncoding)

		// [input-encoding] Gets or sets character encoding Tidy uses for the input. See CharacterEncoding for more info. Defaults to "utf8".
		DECLARE_PROPERTY_ENUM(Encodings, InputCharacterEncoding, TidyInCharEncoding)

		// [newline] Gets or sets the type of newline. The default is appropriate to the current platform: CRLF on PC-DOS, MS-Windows and OS/2, CR on Classic Mac OS, and LF everywhere else (Unix and Linux).
		DECLARE_PROPERTY_ENUM(LineEndings, LineEnding, TidyNewline)

		// [output-bom] Gets or sets whether Tidy should write a Unicode Byte Order Mark character (BOM; also known as Zero Width No-Break Space; has value of U+FEFF) to the beginning of the output; only for UTF-8 and UTF-16 output encodings. If set to "auto", this option causes Tidy to write a BOM to the output only if a BOM was present at the beginning of the input. A BOM is always written for XML/XHTML output using UTF-16 output encodings. Defaults to "Auto".
		DECLARE_PROPERTY_AUTOBOOL(OutputByteOrderMark, TidyOutputBOM)

		// [output-encoding] Gets or sets character encoding Tidy uses for the output. See CharacterEncoding for more info. May only be different from input-encoding for Latin encodings (ascii, latin0, latin1, mac, win1252, ibm858). Defaults to "Utf8".
		DECLARE_PROPERTY_ENUM(Encodings, OutputCharacterEncoding, TidyOutCharEncoding)
	};
}