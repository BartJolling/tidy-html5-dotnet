using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

//TODO: add tests: check for non-zero error count and non-zero access warning count

public class DocumentCountersTests
{
    private readonly ITestOutputHelper _output;
    private readonly List<FeedbackMessage> _tidyMessages = [];

    public DocumentCountersTests(ITestOutputHelper output)
    {
        _output = output;
        _tidyMessages.Clear();
    }

    [Fact]
    public void WarningCounter_should_be_non_zero_on_warning_status()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;

            _tidyMessages.Add(message);
        };

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(3, _tidyMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(2u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);
    }
}
