#include "tidy.h"
using namespace System::Globalization;

using namespace System;
using namespace System::IO;

namespace TidyHtml5Dotnet {
	public ref class Tidy abstract sealed
	{
	private:
		static String^ _libraryVersion = nullptr;
		static DateTime _releaseDate = DateTime::MinValue;

	public:
		static property String^ LibraryVersion
		{
			String^ get()
			{
				if (_libraryVersion == nullptr)
				{
					_libraryVersion = gcnew String(tidyLibraryVersion());
				}
				return _libraryVersion;
			}
		}

		static property DateTime ReleaseDate
		{
			DateTime get()
			{
				if (_releaseDate == DateTime::MinValue)
				{
					auto releaseDate = gcnew String(tidyReleaseDate());
					_releaseDate = DateTime::ParseExact(releaseDate, "yyyy.MM.dd", CultureInfo::InvariantCulture);
				}
				return _releaseDate;
			}
		}
	};
}