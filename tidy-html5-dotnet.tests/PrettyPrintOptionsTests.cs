using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class PrettyPrintOptionsTests
{
    [Fact]
    public void BreakBeforeBR_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.BreakBeforeBR);

        options.BreakBeforeBR = true;
        Assert.True(options.BreakBeforeBR);

        options.BreakBeforeBR = false;
        Assert.False(options.BreakBeforeBR);
    }

    [Fact]
    public void IndentContent_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.IndentContent);

        options.IndentContent = true;
        Assert.True(options.IndentContent);

        options.IndentContent = false;
        Assert.False(options.IndentContent);

        options.IndentContent = null;
        Assert.Null(options.IndentContent);
    }

    [Fact]
    public void IndentAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.IndentAttributes);

        options.IndentAttributes = true;
        Assert.True(options.IndentAttributes);

        options.IndentAttributes = false;
        Assert.False(options.IndentAttributes);
    }

    [Fact]
    public void IndentCData_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.IndentCData);

        options.IndentCData = true;
        Assert.True(options.IndentCData);

        options.IndentCData = false;
        Assert.False(options.IndentCData);
    }

    [Fact]
    public void IndentSpaces_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.Equal(2, options.IndentSpaces);

        options.IndentSpaces = 0;
        Assert.Equal(0, options.IndentSpaces);

        options.IndentSpaces = 1;
        Assert.Equal(1, options.IndentSpaces);

        options.IndentSpaces = 2;
        Assert.Equal(2, options.IndentSpaces);
    }

    [Fact]
    public void IndentWithTabs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.IndentWithTabs);

        options.IndentWithTabs = true;
        Assert.True(options.IndentWithTabs);

        options.IndentWithTabs = false;
        Assert.False(options.IndentWithTabs);
    }

    [Fact]
    public void KeepTabs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.KeepTabs);

        options.KeepTabs = true;
        Assert.True(options.KeepTabs);

        options.KeepTabs = false;
        Assert.False(options.KeepTabs);
    }

    [Fact]
    public void OmitOptionalTags_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.OmitOptionalTags);

        options.OmitOptionalTags = true;
        Assert.True(options.OmitOptionalTags);

        options.OmitOptionalTags = false;
        Assert.False(options.OmitOptionalTags);
    }

    [Fact]
    public void PriorityAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.Empty(options.PriorityAttributes);

        options.PriorityAttributes = ["attributeX", "attributeY", "attributeZ"];
        Assert.NotEmpty(options.PriorityAttributes);
        Assert.Equal(3, options.PriorityAttributes.Count());

        Assert.Equal("attributeX", options.PriorityAttributes.ElementAt(0));
        Assert.Equal("attributeY", options.PriorityAttributes.ElementAt(1));
        Assert.Equal("attributeZ", options.PriorityAttributes.ElementAt(2));

        options.PriorityAttributes = ["attribute1", "attribute2"];
        Assert.NotEmpty(options.PriorityAttributes);
        Assert.Equal(2, options.PriorityAttributes.Count());

        Assert.Equal("attribute1", options.PriorityAttributes.First());
        Assert.Equal("attribute2", options.PriorityAttributes.Last());

        options.PriorityAttributes = [];
        Assert.Empty(options.PriorityAttributes);

        Assert.Throws<ArgumentNullException>(() => options.PriorityAttributes = null);
    }

    [Fact]
    public void PunctuationWrap_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.PunctuationWrap);

        options.PunctuationWrap = true;
        Assert.True(options.PunctuationWrap);

        options.PunctuationWrap = false;
        Assert.False(options.PunctuationWrap);
    }

    [Fact]
    public void SortAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.Equal(SortAttributeStrategy.None, options.SortAttributes);

        options.SortAttributes = SortAttributeStrategy.Alphabetically;
        Assert.Equal(SortAttributeStrategy.Alphabetically, options.SortAttributes);

        options.SortAttributes = SortAttributeStrategy.None;
        Assert.Equal(SortAttributeStrategy.None, options.SortAttributes);        
    }

    [Fact]
    public void TabSize_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.Equal(8, options.TabSize);

        for(int i = 0; i < 9; i++ )
        {
            options.TabSize = i;
            Assert.Equal(i, options.TabSize);
        }
    }

    [Fact]
    public void Mark_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.True(options.Mark);

        options.Mark = false;
        Assert.False(options.Mark);

        options.Mark = true;
        Assert.True(options.Mark);
    }

    [Fact]
    public void VerticalSpace_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.VerticalSpace);

        options.VerticalSpace = true;
        Assert.True(options.VerticalSpace);

        options.VerticalSpace = false;
        Assert.False(options.VerticalSpace);

        options.VerticalSpace = null;
        Assert.Null(options.VerticalSpace);
    }

    [Fact]
    public void WrapLength_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.Equal(68, options.WrapLength);

        for(int i = 0; i < 70; i++ )
        {
            options.WrapLength = i;
            Assert.Equal(i, options.WrapLength);
        }
    }

    [Fact]
    public void WrapAsp_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.True(options.WrapAsp);

        options.WrapAsp = false;
        Assert.False(options.WrapAsp);

        options.WrapAsp = true;
        Assert.True(options.WrapAsp);
    }

    [Fact]
    public void WrapAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.WrapAttributes);

        options.WrapAttributes = true;
        Assert.True(options.WrapAttributes);

        options.WrapAttributes = false;
        Assert.False(options.WrapAttributes);
    }
    
    [Fact]
    public void WrapJste_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.True(options.WrapJste);

        options.WrapJste = false;
        Assert.False(options.WrapJste);

        options.WrapJste = true;
        Assert.True(options.WrapJste);
    }

    [Fact]
    public void WrapPhp_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.WrapPhp);
        
        options.WrapPhp = true;
        Assert.True(options.WrapPhp);

        options.WrapPhp = false;
        Assert.False(options.WrapPhp);
    }

    [Fact]
    public void WrapScriptLiterals_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.False(options.WrapScriptLiterals);

        options.WrapScriptLiterals = true;
        Assert.True(options.WrapScriptLiterals);

        options.WrapScriptLiterals = false;
        Assert.False(options.WrapScriptLiterals);
    }

   [Fact]
    public void WrapSections_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.PrettyPrintOptions;
        Assert.NotNull(options);

        Assert.True(options.WrapSections);

        options.WrapSections = false;
        Assert.False(options.WrapSections);

        options.WrapSections = true;
        Assert.True(options.WrapSections);
    }    
}