using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class EntitiesOptionsTests
{

    [Fact]
    public void AsciiChars_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.False(options.AsciiChars);

        options.AsciiChars = true;
        Assert.True(options.AsciiChars);

        options.AsciiChars = false;
        Assert.False(options.AsciiChars);
    }

    [Fact]
    public void NumericCharacterReferences_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.True(options.NumericCharacterReferences);

        options.NumericCharacterReferences = false;
        Assert.False(options.NumericCharacterReferences);

        options.NumericCharacterReferences = true;
        Assert.True(options.NumericCharacterReferences);
    }

    [Fact]
    public void NumericEntities_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.False(options.NumericEntities);

        options.NumericEntities = true;
        Assert.True(options.NumericEntities);

        options.NumericEntities = false;
        Assert.False(options.NumericEntities);
    }

    [Fact]
    public void PreserveEntities_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.False(options.PreserveEntities);

        options.PreserveEntities = true;
        Assert.True(options.PreserveEntities);

        options.PreserveEntities = false;
        Assert.False(options.PreserveEntities);
    }

    [Fact]
    public void QuoteAmpersands_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.True(options.QuoteAmpersands);

        options.QuoteAmpersands = false;
        Assert.False(options.QuoteAmpersands);

        options.QuoteAmpersands = true;
        Assert.True(options.QuoteAmpersands);
    }

    [Fact]
    public void QuoteMarks_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.False(options.QuoteMarks);

        options.QuoteMarks = true;
        Assert.True(options.QuoteMarks);

        options.QuoteMarks = false;
        Assert.False(options.QuoteMarks);
    }

    [Fact]
    public void QuoteNonBreakingSpaces_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EntitiesOptions;
        Assert.NotNull(options);

        Assert.True(options.QuoteNonBreakingSpaces);

        options.QuoteNonBreakingSpaces = false;
        Assert.False(options.QuoteNonBreakingSpaces);

        options.QuoteNonBreakingSpaces = true;
        Assert.True(options.QuoteNonBreakingSpaces);
    }
}