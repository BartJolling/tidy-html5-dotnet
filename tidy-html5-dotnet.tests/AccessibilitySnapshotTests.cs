using System.Text;
using tidy_html5_dotnet_test.helpers;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

[Collection("Accessibility")]
public class AccessibilitySnapshotTests()
{
    [Theory]
    [DirectoryCasesData("access")] // scans cases/access-cases + cases/access-expects
    public void Accessibility_Case(CaseData testCaseData)
    {
        // Build document from input string
        var reportStream = new MemoryStream();
        var doc = Document.FromFile(testCaseData.InputHtml).WithReportStream(reportStream);       

        // Load config text (if API supports from string; if not, parse/apply options)
        var configStatus = doc.LoadConfig(testCaseData.ConfigFile);
        Assert.Equal(DocumentStatuses.Success, configStatus);

        // Clean & repair
        var cleanStatus = doc.CleanAndRepair();
        Assert.Equal(testCaseData.CleanupStatus, cleanStatus);

        // Compare content
        var receivedContent = doc.ToString();
        Assert.Equal(testCaseData.ExpectedContent, receivedContent);

        // Compare report
        reportStream.Position = 0;
        using var reader = new StreamReader(reportStream, Encoding.UTF8, leaveOpen: false);
        Assert.Equal(testCaseData.ExpectedReport, reader.ReadToEnd());
    }
}
