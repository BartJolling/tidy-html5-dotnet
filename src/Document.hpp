#pragma once

#include "CleanupOptions.hpp"
#include "DiagnosticOptions.hpp"
#include "DisplayOptions.hpp"
#include "Document.hpp"
#include "EncodingOptions.hpp"
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
		CleanupOptions^ _cleanupOptions = nullptr;
		DiagnosticOptions^ _diagnosticOptions = nullptr;
		DisplayOptions^ _displayOptions = nullptr;
		EncodingOptions^ _encodingOptions = nullptr;
		FileOptions^ _fileOptions = nullptr;
		InOutOptions^ _inOutOptions = nullptr;

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
		property CleanupOptions^ CleanupOptions { TidyHtml5Dotnet::CleanupOptions^ get() { return _cleanupOptions; }}
		property DiagnosticOptions^ DiagnosticOptions { TidyHtml5Dotnet::DiagnosticOptions^ get() { return _diagnosticOptions; }}
		property DisplayOptions^ DisplayOptions { TidyHtml5Dotnet::DisplayOptions^ get() { return _displayOptions; }}
		property EncodingOptions^ EncodingOptions { TidyHtml5Dotnet::EncodingOptions^ get() { return _encodingOptions; }}
		property FileOptions^ FileOptions { TidyHtml5Dotnet::FileOptions^ get() { return _fileOptions; }}
		property InOutOptions^ InOutOptions { TidyHtml5Dotnet::InOutOptions^ get() { return _inOutOptions; }}
	};
}