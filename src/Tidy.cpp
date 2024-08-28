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
}