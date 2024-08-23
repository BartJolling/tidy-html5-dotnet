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

	Action<FeedbackMessage^>^ Tidy::FeedbackMessagesCallback::get()
	{
		return _feedbackMessagesCallback;
	}

	void Tidy::FeedbackMessagesCallback::set(Action<FeedbackMessage^>^ value)
	{
		_feedbackMessagesCallback = value;
	}
}