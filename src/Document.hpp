#pragma once

#include "DiagnosticOptions.hpp"
#include "DisplayOptions.hpp"
#include "Document.hpp"
#include "FileOptions.hpp"
#include "InOutOptions.hpp"
#include "Options.hpp"
#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class Document
	{
	private:
		TidyDoc _tidyDoc = nullptr;

		// Options
		Options^ _options = nullptr;
		DiagnosticOptions^ _diagnosticOptions = nullptr;
		DisplayOptions^ _displayOptions = nullptr;
		InOutOptions^ _inOutOptions = nullptr;
		FileOptions^ _fileOptions = nullptr;

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
		property DiagnosticOptions^ DiagnosticOptions { TidyHtml5Dotnet::DiagnosticOptions^ get() { return _diagnosticOptions; }}
		property DisplayOptions^ DisplayOptions { TidyHtml5Dotnet::DisplayOptions^ get() { return _displayOptions; }}
		property InOutOptions^ InOutOptions { TidyHtml5Dotnet::InOutOptions^ get() { return _inOutOptions; }}
		property FileOptions^ FileOptions { TidyHtml5Dotnet::FileOptions^ get() { return _fileOptions; }}
	};
}