using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class FeedbackMessageTests
{
    private readonly ITestOutputHelper _output;
    private readonly List<FeedbackMessage> _tidyMessages = [];

    public FeedbackMessageTests(ITestOutputHelper output)
    {
        _output = output;
        _tidyMessages.Clear();
    }

    [Fact]
    public void FeedbackMessages_With_String_Arguments()
    {
        string htmlString = @"<!DOCTYPE HTML PUBLIC ""-//W3C//DTD HTML 4.01//EN"" ""http://www.w3.org/TR/html4/strict.dtd""><html><head><title>Issue #378</title><meta http-equiv=""Content-type"" content=""text/html; charset=utf-8""></head><body><p><a href=""http://example.com/é"">foo</a></p></body></html>";

        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        tidyDocument.RepairOptions.StrictTagsAttributes = true;
        tidyDocument.FeedbackMessagesCallback = message => _tidyMessages.Add(message);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(3, _tidyMessages.Count);
    }
}
