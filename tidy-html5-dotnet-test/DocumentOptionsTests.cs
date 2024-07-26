using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentOptionsTests
{
    [Fact]
    public void DecorateInferredUL_sets_option_TidyDecorateInferredUL()
    {
        var document = new Document();

        document.Options.DecorateInferredUL = true;
        Assert.True(document.Options.DecorateInferredUL);

        document.Options.DecorateInferredUL = false;
        Assert.False(document.Options.DecorateInferredUL);
    }
}
