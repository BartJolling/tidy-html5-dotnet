#pragma once

#include "Document.hpp"
#include "DisplayOptions.hpp"
#include "Diagnostics.hpp"
#include "Options.hpp"
#include "tidy.h"

using namespace System;
using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class Document
	{
	private:
		TidyDoc _tidyDoc = nullptr;

		// Options
		Options^ _options = nullptr;
		Diagnostics^ _diagnostics = nullptr;
		DisplayOptions^ _displayOptions = nullptr;

		Stream^ _stream = nullptr;
		String^ _htmlString;
		bool _fromString = false;
		bool _disposed = false;
		bool _cleaned = false;

	public:
		Document();
		Document(String^ htmlString);
		Document(Stream^ stream);

		property Options^ Options { TidyHtml5Dotnet::Options^ get() { return _options; }}
		property Diagnostics^ Diagnostics { TidyHtml5Dotnet::Diagnostics^ get() { return _diagnostics; }}
		property DisplayOptions^ DisplayOptions { TidyHtml5Dotnet::DisplayOptions^ get() { return _displayOptions; }}
	};
}