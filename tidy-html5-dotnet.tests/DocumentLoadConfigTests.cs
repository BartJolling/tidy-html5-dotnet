using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentLoadConfigTests
{
    [Fact]
    public void Load_config_must_succeed()
    {
        var configFileName = "DocumentLoadConfigTests.config";

        using var tidyDocument = new Document();
        Assert.NotNull(tidyDocument);

        Assert.Equal(Encodings.Utf8, tidyDocument.EncodingOptions.CharacterEncoding);

        var configStatus = tidyDocument.LoadConfig(configFileName);
        Assert.Equal(DocumentStatuses.Success, configStatus);

        Assert.Equal(Encodings.Latin1, tidyDocument.EncodingOptions.CharacterEncoding);
    }
}