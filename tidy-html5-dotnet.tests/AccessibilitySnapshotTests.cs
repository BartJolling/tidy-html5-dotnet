using System.Diagnostics;
using tidy_html5_dotnet_test.helpers;
using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

[Collection("Accessibility")]
public class AccessibilitySnapshotTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    [Theory]
    [DirectoryCasesData("access")] // scans cases/access-cases + cases/access-expects
    public void Accessibility_Case(CaseData testCaseData)
    {
        // Build document from input string
        var doc = Document.FromFile(testCaseData.InputHtml);

        // Capture messages
        var receivedMessages = new List<string>();
        doc.FeedbackMessagesCallback = message =>
        {
            if(message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;

            //if (message.Key == "STRING_HELLO_ACCESS") 
              // return;

            var output = message.Output?.Trim();

            if (string.IsNullOrWhiteSpace(output))
                return;

            // Split on CRLF or LF, remove empty entries, and trim each line
            var lines = output.Split(["\r\n", "\n"], StringSplitOptions.None);

            foreach (var line in lines)
            {
                var trimmed = line.Trim();
                if (!string.IsNullOrWhiteSpace(trimmed))
                    receivedMessages.Add(trimmed);
            }
        };

        // Load config text (if API supports from string; if not, parse/apply options)
        var configStatus = doc.LoadConfig(testCaseData.ConfigFile);
        Assert.Equal(DocumentStatuses.Success, configStatus);
        
        //TODO: these filters do not affect the message callback. They work on the Error Sink
        //doc.DisplayOptions.Quiet = true;
        //doc.DisplayOptions.ShowInfo = false;

        // Clean & repair
        var cleanStatus = doc.CleanAndRepair();
        Assert.Equal(testCaseData.CleanupStatus, cleanStatus);

        // Compare content
        var receivedContent = doc.ToString();
        Assert.Equal(testCaseData.ExpectedContent, receivedContent);

        // Compare messages
        Assert.Equal(testCaseData.ExpectedMessages, receivedMessages);
    }
}
