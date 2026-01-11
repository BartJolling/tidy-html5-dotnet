using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test.helpers;

public sealed record CaseData(
    string CaseNumber,
    string InputHtml,
    string ConfigFile,
    string ExpectedContent,
    IReadOnlyList<string> ExpectedMessages,
    DocumentStatuses CleanupStatus,
    DocumentStatuses DiagnosticStatus)
{
    public override string ToString() => CaseNumber; // appears in theory display name
}

