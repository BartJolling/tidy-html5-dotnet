using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DocumentOptionDescriptionsTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    [Fact]
    public void GetOptionDescriptions_must_return_values_for_all_options_for_document()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        var opts = tidyDocument.GetOptionDescriptions();

        _output.WriteLine("Name                        Type       Current Value");
        _output.WriteLine("=========================== =========  ========================================");

        foreach (var o in opts)
        {
            _output.WriteLine(String.Format("{0,-27} {1,-9}  {2}", o.Name, o.Type, o.Default));
        }
    }
}
