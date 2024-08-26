#pragma once

#include "Document.hpp"
#include "FeedbackMessage.hpp"
#include "tidy.h"

using namespace System;
using namespace System::Collections::Concurrent;
using namespace System::Globalization;
using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class Tidy abstract sealed
	{
	private:
		static String^ _libraryVersion = gcnew String(tidyLibraryVersion());
		static DateTime _releaseDate = DateTime::ParseExact(gcnew String(tidyReleaseDate()), "yyyy.MM.dd", CultureInfo::InvariantCulture);
		static ConcurrentDictionary<IntPtr, Document^>^ _registeredDocuments = gcnew ConcurrentDictionary<IntPtr, Document^>();

	internal:
		static void RegisterDocument(TidyDoc tidyDoc, Document^ document);
		static Document^ GetRegisteredDocument(TidyDoc tidyDoc);
		static Document^ UnregisterDocument(TidyDoc tidyDoc);

	public:
		static property String^ LibraryVersion
		{
			String^ get();
		}

		static property DateTime ReleaseDate
		{
			DateTime get();
		}
	};
}