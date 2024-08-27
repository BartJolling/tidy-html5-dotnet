#include "Tidy.hpp"

namespace TidyHtml5Dotnet 
{
	String^ Tidy::LibraryVersion::get()
	{
		return _libraryVersion;
	}

	DateTime Tidy::ReleaseDate::get()
	{
		return _releaseDate;
	}

	void Tidy::RegisterDocument(TidyDoc tidyDoc, Document^ document)
	{
		IntPtr tidyDocPointer = IntPtr((void*)tidyDoc);
		Tidy::_registeredDocuments[tidyDocPointer] = document;
	}

	Document^ Tidy::GetRegisteredDocument(TidyDoc tidyDoc)
	{
		IntPtr tidyDocPointer = IntPtr((void*)tidyDoc);
		return Tidy::_registeredDocuments[tidyDocPointer];
	}

	Document^ Tidy::UnregisterDocument(TidyDoc tidyDoc)
	{
		IntPtr tidyDocPointer = IntPtr((void*)tidyDoc);
		Document^ removedDocument;
		Tidy::_registeredDocuments->TryRemove(tidyDocPointer, removedDocument);
		return removedDocument;
	}
}