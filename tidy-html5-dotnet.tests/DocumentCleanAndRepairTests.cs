using System.Text;
using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DocumentCleanAndRepairTests
{
    private readonly ITestOutputHelper _output;
    private readonly List<FeedbackMessage> _tidyMessages = [];

    public DocumentCleanAndRepairTests(ITestOutputHelper output)
    {
        _output = output;
        _tidyMessages.Clear();
    }

    [Fact]
    public void CleanAndRepair_Document_without_parameters_must_succeed()
    {
        using var tidyDocument = new Document();
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message => _tidyMessages.Add(message);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Success, status);

        Assert.Empty(_tidyMessages);
    }

    [Fact]
    public void CleanAndRepair_Document_from_String_must_succeed()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message => _tidyMessages.Add(message);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(2, _tidyMessages.Count);
    }

    [Fact]
    public void CleanAndRepair_from_Stream_must_succeed()
    {
        var htmlStream = new MemoryStream(Encoding.UTF8.GetBytes("<body><h1>Title</h1></body>"));
        using var tidyDocument = new Document(htmlStream);
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message => _tidyMessages.Add(message);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(2, _tidyMessages.Count);
    }
}