#pragma once

#include "FeedbackMessage.hpp"
#include "tidy.h"

using namespace System;
using namespace System::Globalization;
using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class Tidy abstract sealed
	{
	private:
		static String^ _libraryVersion = gcnew String(tidyLibraryVersion());
		static DateTime _releaseDate = DateTime::ParseExact(gcnew String(tidyReleaseDate()), "yyyy.MM.dd", CultureInfo::InvariantCulture);
		static Action<FeedbackMessage^>^ _feedbackMessagesCallback = nullptr;

	public:
		static property String^ LibraryVersion
		{
			String^ get();
		}

		static property DateTime ReleaseDate
		{
			DateTime get();
		}

		static property Action<FeedbackMessage^>^ FeedbackMessagesCallback
		{
			Action<FeedbackMessage^>^ get();
			void set(Action<FeedbackMessage^>^ value);
		}
	};
}