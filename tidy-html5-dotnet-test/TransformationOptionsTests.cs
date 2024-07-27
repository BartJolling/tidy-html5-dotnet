using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class TransformationOptionsTests
{
    [Fact]
    public void DecorateInferredUL_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.False(options.DecorateInferredUL);

        options.DecorateInferredUL = true;
        Assert.True(options.DecorateInferredUL);

        options.DecorateInferredUL = false;
        Assert.False(options.DecorateInferredUL);
    }

    [Fact]
    public void EscapeCdata_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.False(options.EscapeCdata);

        options.EscapeCdata = true;
        Assert.True(options.EscapeCdata);

        options.EscapeCdata = false;
        Assert.False(options.EscapeCdata);
    }

    [Fact]
    public void HideComments_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.False(options.HideComments);

        options.HideComments = true;
        Assert.True(options.HideComments);

        options.HideComments = false;
        Assert.False(options.HideComments);
    }

    [Fact]
    public void JoinClasses_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.False(options.JoinClasses);

        options.JoinClasses = true;
        Assert.True(options.JoinClasses);

        options.JoinClasses = false;
        Assert.False(options.JoinClasses);
    }

    [Fact]
    public void JoinStyles_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.True(options.JoinStyles);

        options.JoinStyles = false;
        Assert.False(options.JoinStyles);
        
        options.JoinStyles = true;
        Assert.True(options.JoinStyles);
    }

    [Fact]
    public void MergeEmphasis_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.True(options.MergeEmphasis);

        options.MergeEmphasis = false;
        Assert.False(options.MergeEmphasis);

        options.MergeEmphasis = true;
        Assert.True(options.MergeEmphasis);
    }

    [Fact]
    public void ReplaceColor_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.TransformationOptions;
        Assert.NotNull(options);

        Assert.False(options.ReplaceColor);

        options.ReplaceColor = true;
        Assert.True(options.ReplaceColor);

        options.ReplaceColor = false;
        Assert.False(options.ReplaceColor);
    }
}
