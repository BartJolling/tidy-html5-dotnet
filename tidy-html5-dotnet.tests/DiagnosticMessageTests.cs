using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DiagnosticMessageTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    [Fact]
    public void Document_CleanAndRepair_ReturnsDiagnosticMessages()
    {
        string htmlString = @"<!DOCTYPE HTML PUBLIC ""-//W3C//DTD HTML 4.01//EN"" ""http://www.w3.org/TR/html4/strict.dtd""><html><head><title>Issue #378</title><meta http-equiv=""Content-type"" content=""text/html; charset=utf-8""></head><body><p><a href=""http://example.com/é"">foo</a></p></body></html>";

        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        tidyDocument.RepairOptions.StrictTagsAttributes = true;

        var status = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, status);

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine(message.ToString());
        }

        Assert.Equal(8, tidyDocument.DiagnosticMessages.Count);
    }
}
