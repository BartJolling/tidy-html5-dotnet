using System.Text;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentSaveToStreamTests
{
    [Fact]
    public void Save_Document_to_stream_after_clean_must_succeed()
    {
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        using var outputStream = new MemoryStream();
        var saveStatus = tidyDocument.ToStream(outputStream);

        Assert.Equal(DocumentStatuses.Warnings, saveStatus);

        outputStream.Position = 0;
        using var reader = new StreamReader(outputStream, Encoding.UTF8);
        string content = reader.ReadToEnd();

        Assert.Equal("<!DOCTYPE html>\r\n<html>\r\n<head>\r\n<meta name=\"generator\" content=\r\n\"HTML Tidy for HTML5 for Windows version 5.8.0\">\r\n<title></title>\r\n</head>\r\n<body>\r\n<h1>Title</h1>\r\n</body>\r\n</html>\r\n", content);
    }
}