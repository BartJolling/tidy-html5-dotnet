using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentSaveToStringTests
{
    [Fact]
    public void Save_Document_to_string_after_clean_must_succeed()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        var content = tidyDocument.ToString();

        Assert.Equal("<html>\r\n<head>\r\n<title></title>\r\n</head>\r\n<body>\r\n<h1>Title</h1>\r\n</body>\r\n</html>\r\n", content);
    }
}