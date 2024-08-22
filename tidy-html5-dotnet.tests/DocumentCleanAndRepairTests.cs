using System.Text;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentCleanAndRepairTests
{
    private readonly List<string> _tidyMessages = [];

    public DocumentCleanAndRepairTests()
    {
        _tidyMessages.Clear();
        Tidy.MessageCallback = message => _tidyMessages.Add(message);
    }

    [Fact]
    public void CleanAndRepair_Document_without_parameters_must_succeed()
    {
        using var tidyDocument = new Document();
        Assert.NotNull(tidyDocument);

        tidyDocument.ReceiveMessages = true;

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

        tidyDocument.ReceiveMessages = true;

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        Assert.Equal(2, _tidyMessages.Count);
    }

    [Fact]
    public void CleanAndRepair_from_Stream_must_succeed()
    {
        var htmlStream = new MemoryStream(Encoding.UTF8.GetBytes("<body><h1>Title</h1></body>"));
        using var tidyDocument = new Document(htmlStream);
        Assert.NotNull(tidyDocument);

        tidyDocument.ReceiveMessages = true;

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        Assert.Equal(2, _tidyMessages.Count);
    }
}