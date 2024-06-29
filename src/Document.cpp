#include "pch.h"
#include "tidy.h"

using namespace System;
using namespace System::IO;

namespace TidyHtml5Dotnet {
	public ref class Document
	{
	private:
		TidyDoc _tidyDoc = nullptr;
		Stream^ _stream = nullptr;
		String^ _htmlString;
		bool _fromString = false;
		bool _disposed = false;
		bool _cleaned = false;

	public:
		Document()
		{
			_tidyDoc = tidyCreate();
		};

		Document(String^ htmlString) : Document()
		{
			_htmlString = htmlString;
			_fromString = true;
		};

		Document(Stream^ stream) : Document()
		{
			_stream = stream;
		}
	};
}

