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

	Action<String^>^ Tidy::MessageCallback::get()
	{
		return _messageCallback;
	}

	void Tidy::MessageCallback::set(Action<String^>^ value)
	{
		_messageCallback = value;
	}
}