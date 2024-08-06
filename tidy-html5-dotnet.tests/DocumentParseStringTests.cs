using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentParseStringTests
{
    [Fact]
    public void ParseString_must_return_status()
    {
        using var document = new Document("<h1>heading</h1>");
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        var result = document.ParseString();
        Assert.Equal(DocumentStatuses.WithWarnings, result);
    }
}
