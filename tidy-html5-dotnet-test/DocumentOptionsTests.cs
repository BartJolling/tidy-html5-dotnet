using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DocumentOptionsTests
{
    [Fact]
    public void DefaultAltText_sets_option_TidyAltText()
    {
        var document = new Document();
        Assert.Equal(String.Empty, document.Options.DefaultAltText);

        document.Options.DefaultAltText = "Default Alt Text";
        Assert.Equal("Default Alt Text", document.Options.DefaultAltText);
    }

    [Fact]
    public void AnchorAsName_sets_option_AnchorAsNamee()
    {
        var document = new Document();

        document.Options.AnchorAsName = true;
        Assert.True(document.Options.AnchorAsName);

        document.Options.AnchorAsName = false;
        Assert.False(document.Options.AnchorAsName);
    }

    [Fact]
    public void ChangeXmlProcessingInstructions_sets_option_TidyXmlPIs()
    {
        var document = new Document();

        document.Options.ChangeXmlProcessingInstructions = true;
        Assert.True(document.Options.ChangeXmlProcessingInstructions);

        document.Options.ChangeXmlProcessingInstructions = false;
        Assert.False(document.Options.ChangeXmlProcessingInstructions);
    }



    [Fact]
    public void CoerceEndTags_sets_option_TidyCoerceEndTags()
    {
        var document = new Document();

        document.Options.CoerceEndTags = true;
        Assert.True(document.Options.CoerceEndTags);

        document.Options.CoerceEndTags = false;
        Assert.False(document.Options.CoerceEndTags);
    }

    [Fact]
    public void CssPrefix_sets_option_TidyCSSPrefix()
    {
        var document = new Document();
        Assert.Equal("c", document.Options.CssPrefix);
        
        document.Options.CssPrefix = "css-prefix";            
        Assert.Equal("css-prefix", document.Options.CssPrefix);
    }

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
