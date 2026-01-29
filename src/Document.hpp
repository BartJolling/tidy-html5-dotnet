#pragma once

#include "CleanupOptions.hpp"
#include "DiagnosticOptions.hpp"
#include "DisplayOptions.hpp"
#include "Document.hpp"
#include "DocumentOptionsView.hpp"
#include "DocumentStatuses.hpp"
#include "EncodingOptions.hpp"
#include "EntitiesOptions.hpp"
#include "FeedbackMessage.hpp"
#include "FileOptions.hpp"
#include "IncludeInReport.hpp"
#include "InOutOptions.hpp"
#include "InputSource.hpp"
#include "PrettyPrintOptions.hpp"
#include "RepairOptions.hpp"
#include "StreamSink.hpp"
#include "TeachingOptions.hpp"
#include "TransformationOptions.hpp"
#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	private delegate Bool TidyMessageDelegate(TidyMessage tmessage);

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

		Int64 _inputLength = 0;
		InputSource^ _inputSource = nullptr;
		ctmbstr _contentString;

		// Tidy messages (between Tidy and Document)		
		TidyMessageDelegate^ _tidyMessageDelegate;
		Bool OnReceiveTidyMessage(TidyMessage tmessage);

		// Diagnostic messages (between Document and its users)
		List<FeedbackMessage^>^ _diagnosticMessages = gcnew List<FeedbackMessage^>();

		// Handle Tidy report output
		StreamSink^ _reportStreamSink = nullptr;

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

		DocumentStatuses LoadConfig(String^ filePath, [Optional] Nullable<Encodings> encoding);
		DocumentStatuses CleanAndRepair();
		DocumentStatuses CleanAndRepair(Stream^ reportStream);
		DocumentStatuses CleanAndRepair(String^ reportFilePath);
		DocumentStatuses ReportDocType();
		DocumentStatuses RunDiagnostics();
		void ErrorSummary();
		void GeneralInfo();

		Func<FeedbackMessage^, IncludeInReport>^ OnReceiveDiagnosticMessage;
		property IReadOnlyList<FeedbackMessage^>^ DiagnosticMessages 
		{
			IReadOnlyList<FeedbackMessage^>^ get() { return _diagnosticMessages; }
		};

		virtual String^ ToString() override;
		DocumentStatuses ToFile(String^ filePath);
		DocumentStatuses ToStream(Stream^ stream);

		property uint AccessWarningCount { uint get(); }
		property uint ErrorCount { uint get(); }
		property uint WarningCount { uint get(); }

		IReadOnlyList<OptionDescription^>^ GetOptionDescriptions();

		// Configuration
		property CleanupOptions^ CleanupOptions { TidyHtml5Dotnet::CleanupOptions^ get() { return _cleanupOptions; } }
		property DiagnosticOptions^ DiagnosticOptions { TidyHtml5Dotnet::DiagnosticOptions^ get() { return _diagnosticOptions; } }
		property DisplayOptions^ DisplayOptions { TidyHtml5Dotnet::DisplayOptions^ get() { return _displayOptions; } }
		property EncodingOptions^ EncodingOptions { TidyHtml5Dotnet::EncodingOptions^ get() { return _encodingOptions; } }
		property EntitiesOptions^ EntitiesOptions { TidyHtml5Dotnet::EntitiesOptions^ get() { return _entitiesOptions; } }
		property FileOptions^ FileOptions { TidyHtml5Dotnet::FileOptions^ get() { return _fileOptions; } }
		property InOutOptions^ InOutOptions { TidyHtml5Dotnet::InOutOptions^ get() { return _inOutOptions; } }
		property PrettyPrintOptions^ PrettyPrintOptions { TidyHtml5Dotnet::PrettyPrintOptions^ get() { return _prettyPrintOptions; } }
		property RepairOptions^ RepairOptions { TidyHtml5Dotnet::RepairOptions^ get() { return _repairOptions; } }
		property TeachingOptions^ TeachingOptions { TidyHtml5Dotnet::TeachingOptions^ get() { return _teachingOptions; } }
		property TransformationOptions^ TransformationOptions { TidyHtml5Dotnet::TransformationOptions^ get() { return _transformationOptions; } }
	};
}