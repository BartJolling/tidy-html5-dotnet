using TidyHtml5Dotnet;
using Xunit.Sdk;

namespace tidy_html5_dotnet_test.helpers;

public sealed record CaseData : IXunitSerializable
{
    public string CaseNumber { get; set; } = default!;
    public string InputHtml { get; set; } = default!;
    public string ConfigFile { get; set; } = default!;
    public string ExpectedContent { get; set; } = default!;
    public string ExpectedReport { get; set; } = default!;
    public DocumentStatuses CleanupStatus { get; set; }
    public DocumentStatuses DiagnosticStatus { get; set; }

    public CaseData() { } // required
    public CaseData(
    string caseNumber,
    string inputHtml,
    string configFile,
    string expectedContent,
    string expectedReport,
    DocumentStatuses cleanupStatus,
    DocumentStatuses diagnosticStatus)
    {
        CaseNumber = caseNumber;
        InputHtml = inputHtml;
        ConfigFile = configFile;
        ExpectedContent = expectedContent;
        ExpectedReport = expectedReport;
        CleanupStatus = cleanupStatus;
        DiagnosticStatus = diagnosticStatus;
    }

    public override string ToString() => CaseNumber; // appears in theory display name

    public void Serialize(IXunitSerializationInfo info)
    {
        info.AddValue(nameof(CaseNumber), CaseNumber);
        info.AddValue(nameof(InputHtml), InputHtml);
        info.AddValue(nameof(ConfigFile), ConfigFile);
        info.AddValue(nameof(ExpectedContent), ExpectedContent);
        info.AddValue(nameof(ExpectedReport), ExpectedReport);
        info.AddValue(nameof(CleanupStatus), CleanupStatus);
        info.AddValue(nameof(DiagnosticStatus), DiagnosticStatus);
    }

    public void Deserialize(IXunitSerializationInfo info)
    {
        CaseNumber = info.GetValue<string>(nameof(CaseNumber))!;
        InputHtml = info.GetValue<string>(nameof(InputHtml))!;
        ConfigFile = info.GetValue<string>(nameof(ConfigFile))!;
        ExpectedContent = info.GetValue<string>(nameof(ExpectedContent))!;
        ExpectedReport = info.GetValue<string>(nameof(ExpectedReport))!;
        CleanupStatus = info.GetValue<DocumentStatuses>(nameof(CleanupStatus));
        DiagnosticStatus = info.GetValue<DocumentStatuses>(nameof(DiagnosticStatus));
    }    
}