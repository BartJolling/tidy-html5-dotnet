using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class RepairOptionsTests
{
    [Fact]
    public void DefaultAltText_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Equal(String.Empty, options.DefaultAltText);

        options.DefaultAltText = "Default Alt Text";
        Assert.Equal("Default Alt Text", options.DefaultAltText);

        options.DefaultAltText = string.Empty;
        Assert.Empty(options.DefaultAltText);
    }

    [Fact]
    public void AnchorAsName_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.AnchorAsName);

        options.AnchorAsName = false;
        Assert.False(options.AnchorAsName);

        options.AnchorAsName = true;
        Assert.True(options.AnchorAsName);
    }

    [Fact]
    public void ChangeXmlProcessingInstructions_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.ChangeXmlProcessingInstructions);

        options.ChangeXmlProcessingInstructions = true;
        Assert.True(options.ChangeXmlProcessingInstructions);

        options.ChangeXmlProcessingInstructions = false;
        Assert.False(options.ChangeXmlProcessingInstructions);
    }

    [Fact]
    public void CoerceEndTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.CoerceEndTags);

        options.CoerceEndTags = false;
        Assert.False(options.CoerceEndTags);

        options.CoerceEndTags = true;
        Assert.True (options.CoerceEndTags);
    }

    [Fact]
    public void CssPrefix_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Equal("c", options.CssPrefix);

        options.CssPrefix = "abc";
        Assert.Equal("abc", options.CssPrefix);
    }

    [Fact]
    public void UseCustomTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Equal(UseCustomTagsStates.No, options.UseCustomTags);

        options.UseCustomTags = UseCustomTagsStates.Blocklevel;
        Assert.Equal(UseCustomTagsStates.Blocklevel, options.UseCustomTags);

        options.UseCustomTags = UseCustomTagsStates.Empty;
        Assert.Equal(UseCustomTagsStates.Empty, options.UseCustomTags);

        options.UseCustomTags = UseCustomTagsStates.Inline;
        Assert.Equal(UseCustomTagsStates.Inline, options.UseCustomTags);

        options.UseCustomTags = UseCustomTagsStates.Pre;
        Assert.Equal(UseCustomTagsStates.Pre, options.UseCustomTags);

        options.UseCustomTags = UseCustomTagsStates.No;
        Assert.Equal(UseCustomTagsStates.No, options.UseCustomTags);
    }

    [Fact]
    public void EncloseBlockText_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.EncloseBlockText);

        options.EncloseBlockText = true;
        Assert.True(options.EncloseBlockText);

        options.EncloseBlockText = false;
        Assert.False(options.EncloseBlockText);
    }

    [Fact]
    public void EncloseBodyText_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.EncloseBodyText);

        options.EncloseBodyText = true;
        Assert.True(options.EncloseBodyText);

        options.EncloseBodyText = false;
        Assert.False(options.EncloseBodyText);
    }

    [Fact]
    public void EscapeScripts_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.EscapeScripts);

        options.EscapeScripts = false;
        Assert.False(options.EscapeScripts);

        options.EscapeScripts = true;
        Assert.True(options.EscapeScripts);
    }

    [Fact]
    public void FixUrlBackslashes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.FixUrlBackslashes);

        options.FixUrlBackslashes = false;
        Assert.False(options.FixUrlBackslashes);

        options.FixUrlBackslashes = true;
        Assert.True(options.FixUrlBackslashes);
    }

    [Fact]
    public void FixBadComments_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Null(options.FixBadComments);

        options.FixBadComments = false;
        Assert.False(options.FixBadComments);

        options.FixBadComments = true;
        Assert.True(options.FixBadComments);

        options.FixBadComments = null;
        Assert.Null(options.FixBadComments);
    }

    [Fact]
    public void FixStyleTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.FixStyleTags);

        options.FixStyleTags = false;
        Assert.False(options.FixStyleTags);

        options.FixStyleTags = true;
        Assert.True(options.FixStyleTags);
    }

    [Fact]
    public void FixAttributeUris_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.FixAttributeUris);

        options.FixAttributeUris = false;
        Assert.False(options.FixAttributeUris);

        options.FixAttributeUris = true;
        Assert.True(options.FixAttributeUris);
    }

    [Fact]
    public void LiteralAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.LiteralAttributes);

        options.LiteralAttributes = true;
        Assert.True(options.LiteralAttributes);

        options.LiteralAttributes = false;
        Assert.False(options.LiteralAttributes);
    }

    [Fact]
    public void LowerCaseLiterals_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.LowerCaseLiterals);

        options.LowerCaseLiterals = false;
        Assert.False(options.LowerCaseLiterals);

        options.LowerCaseLiterals = true;
        Assert.True(options.LowerCaseLiterals);
    }

    [Fact]
    public void RepeatedAttributeMode_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Equal(RepeatedAttributeModes.KeepLast, options.RepeatedAttributeMode);

        options.RepeatedAttributeMode = RepeatedAttributeModes.KeepFirst;
        Assert.Equal(RepeatedAttributeModes.KeepFirst, options.RepeatedAttributeMode);

        options.RepeatedAttributeMode = RepeatedAttributeModes.KeepLast;
        Assert.Equal(RepeatedAttributeModes.KeepLast, options.RepeatedAttributeMode);
    }

    [Fact]
    public void SkipNestedTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.True(options.SkipNestedTags);

        options.SkipNestedTags = false;
        Assert.False(options.SkipNestedTags);

        options.SkipNestedTags = true;
        Assert.True(options.SkipNestedTags);
    }

    [Fact]
    public void StrictTagsAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.StrictTagsAttributes);

        options.StrictTagsAttributes = true;
        Assert.True(options.StrictTagsAttributes);

        options.StrictTagsAttributes = false;
        Assert.False(options.StrictTagsAttributes);
    }

    [Fact]
    public void UpperCaseAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.Equal(UpperCaseModes.No, options.UpperCaseAttributes);

        options.UpperCaseAttributes = UpperCaseModes.Yes;
        Assert.Equal(UpperCaseModes.Yes, options.UpperCaseAttributes);

        options.UpperCaseAttributes = UpperCaseModes.Preserve;
        Assert.Equal(UpperCaseModes.Preserve, options.UpperCaseAttributes);

        options.UpperCaseAttributes = UpperCaseModes.No;
        Assert.Equal(UpperCaseModes.No, options.UpperCaseAttributes);        
    }

    [Fact]
    public void UpperCaseTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.RepairOptions;
        Assert.NotNull(options);

        Assert.False(options.UpperCaseTags);

        options.UpperCaseTags = true;
        Assert.True(options.UpperCaseTags);

        options.UpperCaseTags = false;
        Assert.False(options.UpperCaseTags);
    }
}