#pragma once

#include "CleanupOptions.hpp"
#include "DiagnosticOptions.hpp"
#include "DisplayOptions.hpp"
#include "Document.hpp"
#include "DocumentStatuses.hpp"
#include "EncodingOptions.hpp"
#include "EntitiesOptions.hpp"
#include "FileOptions.hpp"
#include "InOutOptions.hpp"
#include "InputSource.hpp"
#include "PrettyPrintOptions.hpp"
#include "RepairOptions.hpp"
#include "TeachingOptions.hpp"
#include "TransformationOptions.hpp"
#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class Document
	{
	private:
		TidyDoc _tidyDoc = nullptr;

		// Options
		CleanupOptions^ _cleanupOptions = nullptr;
		DiagnosticOptions^ _diagnosticOptions = nullptr;
		DisplayOptions^ _displayOptions = nullptr;
		EncodingOptions^ _encodingOptions = nullptr;
		EntitiesOptions^ _entitiesOptions = nullptr;
		FileOptions^ _fileOptions = nullptr;
		InOutOptions^ _inOutOptions = nullptr;
		PrettyPrintOptions^ _prettyPrintOptions = nullptr;
		RepairOptions^ _repairOptions = nullptr;
		TeachingOptions^ _teachingOptions = nullptr;
		TransformationOptions^ _transformationOptions = nullptr;

		InputSource^ _inputSource = nullptr;
		ctmbstr _contentString;
		bool _cleaned = false;

		bool _disposed = false;		

	public:
		Document();
		Document(String^ htmlString);
		Document(Stream^ stream);

		static Document^ FromString(String^ htmlString);
		static Document^ FromFile(String^ filePath);
		static Document^ FromStream(Stream^ stream);

		~Document();
		!Document();

		DocumentStatuses CleanAndRepair();

		property CleanupOptions^ CleanupOptions { TidyHtml5Dotnet::CleanupOptions^ get() { return _cleanupOptions; }}
		property DiagnosticOptions^ DiagnosticOptions { TidyHtml5Dotnet::DiagnosticOptions^ get() { return _diagnosticOptions; }}
		property DisplayOptions^ DisplayOptions { TidyHtml5Dotnet::DisplayOptions^ get() { return _displayOptions; }}
		property EncodingOptions^ EncodingOptions { TidyHtml5Dotnet::EncodingOptions^ get() { return _encodingOptions; }}
		property EntitiesOptions^ EntitiesOptions { TidyHtml5Dotnet::EntitiesOptions^ get() { return _entitiesOptions; }}
		property FileOptions^ FileOptions { TidyHtml5Dotnet::FileOptions^ get() { return _fileOptions; }}
		property InOutOptions^ InOutOptions { TidyHtml5Dotnet::InOutOptions^ get() { return _inOutOptions; }}
		property PrettyPrintOptions^ PrettyPrintOptions { TidyHtml5Dotnet::PrettyPrintOptions^ get() { return _prettyPrintOptions; }}
		property RepairOptions^ RepairOptions { TidyHtml5Dotnet::RepairOptions^ get() { return _repairOptions; }}
		property TeachingOptions^ TeachingOptions { TidyHtml5Dotnet::TeachingOptions^ get() { return _teachingOptions; }}
		property TransformationOptions^ TransformationOptions { TidyHtml5Dotnet::TransformationOptions^ get() { return _transformationOptions; }}
	};
}