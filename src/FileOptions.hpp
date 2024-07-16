#pragma once

#include "Conversions.hpp"
#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	/// <summary>
	/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#FileIOHeader
	/// </summary>
	public ref class FileOptions
	{
	private:
		TidyDoc _tidyDoc = nullptr;

	internal:
		FileOptions(const TidyDoc tidyDoc)
		{
			assert(tidyDoc);
			_tidyDoc = tidyDoc;
		};

	public:
		
		// [error-file] Gets or sets the error file Tidy uses for errors and warnings. Normally errors and warnings are output to "stderr". Defaults to null.
		DECLARE_PROPERTY_FILEINFO(ErrorFile, TidyErrFile)		

		// [keep-time] Gets or sets whether Tidy should keep the original modification time of files that Tidy modifies in place. The default is no. Setting the option to yes allows you to tidy files without causing these files to be uploaded to a web server when using a tool such as SiteCopy. Note this feature is not supported on some platforms. Defaults to false.
		DECLARE_PROPERTY_BOOL(KeepTime, TidyKeepFileTimes)

		// [output-file] Gets or sets the output file Tidy uses for markup. Normally markup is written to "stdout". Defaults to null.
		DECLARE_PROPERTY_FILEINFO(OutputFile, TidyOutFile)

		// [write-back] Gets or sets whether Tidy should write back the tidied markup to the same file it read from. You are advised to keep copies of important files before tidying them, as on rare occasions the result may not be what you expect. Defaults to false.
		DECLARE_PROPERTY_BOOL(WriteBack, TidyWriteBack)
	};
}