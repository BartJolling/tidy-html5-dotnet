using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DocumentOptionInfoTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    [Fact]
    public void GetOptionsValues_Document_must_return_values_for_options()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        var opts = tidyDocument.GetOptionsValues();

        _output.WriteLine("Id  Name                        Type       Current Value");
        _output.WriteLine("=== =========================== =========  ========================================");

        foreach (var o in opts)
        {
            _output.WriteLine(String.Format("{0,-3} {1,-27} {2,-9}  {3}", o.Id, o.Name, o.Type, o.Value));
        }
    }
}

