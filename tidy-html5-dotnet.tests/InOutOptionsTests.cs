using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class InOutOptionsTests
{
    [Fact]
    public void AddMetaCharset_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.AddMetaCharset);

        options.AddMetaCharset = true;
        Assert.True(options.AddMetaCharset);

        options.AddMetaCharset = false;
        Assert.False(options.AddMetaCharset);
    }

    [Fact]
    public void AddXmlDeclaration_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.AddXmlDeclaration);

        options.AddXmlDeclaration = true;
        Assert.True(options.AddXmlDeclaration);

        options.AddXmlDeclaration = false;
        Assert.False(options.AddXmlDeclaration);
    }

    [Fact]
    public void AddXmlSpace_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.AddXmlSpace);

        options.AddXmlSpace = true;
        Assert.True(options.AddXmlSpace);

        options.AddXmlSpace = false;
        Assert.False(options.AddXmlSpace);
    }

    [Fact]
    public void DocType_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.Equal(DocTypeModes.Auto, options.DocTypeMode);

        options.DocTypeMode = DocTypeModes.Html5;
        Assert.Equal(DocTypeModes.Html5, options.DocTypeMode);

        options.DocTypeMode = DocTypeModes.Omit;
        Assert.Equal(DocTypeModes.Omit, options.DocTypeMode);

        options.DocTypeMode = DocTypeModes.Strict;
        Assert.Equal(DocTypeModes.Strict, options.DocTypeMode);

        options.DocTypeMode = DocTypeModes.Loose;
        Assert.Equal(DocTypeModes.Loose, options.DocTypeMode);

        options.DocTypeMode = DocTypeModes.User;
        Assert.Equal(DocTypeModes.User, options.DocTypeMode);
    }

    [Fact]
    public void InputXml_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.InputXml);

        options.InputXml = true;
        Assert.True(options.InputXml);

        options.InputXml = false;
        Assert.False(options.InputXml);
    }

    [Fact]
    public void OutputHtml_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.OutputHtml);

        options.OutputHtml = true;
        Assert.True(options.OutputHtml);

        options.OutputHtml = false;
        Assert.False(options.OutputHtml);
    }

    [Fact]
    public void OutputXhtml_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.OutputXhtml);

        options.OutputXhtml = true;
        Assert.True(options.OutputXhtml);

        options.OutputXhtml = false;
        Assert.False(options.OutputXhtml);
    }

    [Fact]
    public void OutputXml_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.InOutOptions;
        Assert.NotNull(options);

        Assert.False(options.OutputXml);

        options.OutputXml = true;
        Assert.True(options.OutputXml);

        options.OutputXml = false;
        Assert.False(options.OutputXml);
    }
}