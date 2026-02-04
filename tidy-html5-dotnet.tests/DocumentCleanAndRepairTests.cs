using System.Text;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentCleanAndRepairTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    [Fact]
    public void CleanAndRepair_Document_without_parameters_must_succeed()
    {
        using var tidyDocument = new Document();
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage =
            message => (message.Level == ReportLevel.Info ||
                        message.Level == ReportLevel.DialogueInfo)
                ? IncludeInReport.No
                : IncludeInReport.Yes;

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Success, status);

        Assert.Empty(tidyDocument.DiagnosticMessages);
    }

    [Fact]
    public void CleanAndRepair_Document_from_String_must_succeed()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(4, tidyDocument.DiagnosticMessages.Count);
    }

    [Fact]
    public void CleanAndRepair_from_Stream_must_succeed()
    {
        var htmlStream = new MemoryStream(Encoding.UTF8.GetBytes("<body><h1>Title</h1></body>"));
        using var tidyDocument = new Document(htmlStream);
        Assert.NotNull(tidyDocument);

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(4, tidyDocument.DiagnosticMessages.Count);
    }
}