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
        Assert.Equal(AccessibilityCheckLevels.TidyClassic, tidyDocument.DiagnosticOptions.AccessibilityCheckLevel);
        Assert.True(tidyDocument.DisplayOptions.ShowInfo);

        var configStatus = tidyDocument.LoadConfig(configFileName);
        Assert.Equal(DocumentStatuses.Success, configStatus);

        Assert.Equal(Encodings.Latin1, tidyDocument.EncodingOptions.CharacterEncoding);
        Assert.Equal(AccessibilityCheckLevels.Priority1, tidyDocument.DiagnosticOptions.AccessibilityCheckLevel);
        Assert.False(tidyDocument.DisplayOptions.ShowInfo);
    }
}