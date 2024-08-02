using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class CleanupOptionsTests
{
    [Fact]
    public void MakeBare_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.MakeBare);

        options.MakeBare = true;
        Assert.True(options.MakeBare);

        options.MakeBare = false;
        Assert.False(options.MakeBare);
    }

    [Fact]
    public void MakeClean_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.MakeClean);

        options.MakeClean = true;
        Assert.True(options.MakeClean);

        options.MakeClean = false;
        Assert.False(options.MakeClean);
    }

    [Fact]
    public void DropEmptyElements_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.True(options.DropEmptyElements);

        options.DropEmptyElements = false;
        Assert.False(options.DropEmptyElements);

        options.DropEmptyElements = true;
        Assert.True(options.DropEmptyElements);
    }

    [Fact]
    public void DropEmptyParagraphs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.True(options.DropEmptyParagraphs);

        options.DropEmptyParagraphs = false;
        Assert.False(options.DropEmptyParagraphs);

        options.DropEmptyParagraphs = true;
        Assert.True(options.DropEmptyParagraphs);
    }

    [Fact]
    public void DropProprietaryAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.DropProprietaryAttributes);

        options.DropProprietaryAttributes = true;
        Assert.True(options.DropProprietaryAttributes);

        options.DropProprietaryAttributes = false;
        Assert.False(options.DropProprietaryAttributes);
    }

    [Fact]
    public void CleanGoogleDocs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.CleanGoogleDocs);

        options.CleanGoogleDocs = true;
        Assert.True(options.CleanGoogleDocs);

        options.CleanGoogleDocs = false;
        Assert.False(options.CleanGoogleDocs);
    }

    [Fact]
    public void LogicalEmphasis_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.LogicalEmphasis);

        options.LogicalEmphasis = true;
        Assert.True(options.LogicalEmphasis);

        options.LogicalEmphasis = false;
        Assert.False(options.LogicalEmphasis);
    }

    [Fact]
    public void MergeDivs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.Null(options.MergeDivs);

        options.MergeDivs = true;
        Assert.True(options.MergeDivs);

        options.MergeDivs = false;
        Assert.False(options.MergeDivs);

        options.MergeDivs = null;
        Assert.Null(options.MergeDivs);
    }

    [Fact]
    public void MergeSpans_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.Null(options.MergeSpans);

        options.MergeSpans = true;
        Assert.True(options.MergeSpans);

        options.MergeSpans = false;
        Assert.False(options.MergeSpans);

        options.MergeSpans = null;
        Assert.Null(options.MergeSpans);
    }

    [Fact]
    public void CleanWord2000_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.CleanupOptions;
        Assert.NotNull(options);

        Assert.False(options.CleanWord2000);

        options.CleanWord2000 = true;
        Assert.True(options.CleanWord2000);

        options.CleanWord2000 = false;
        Assert.False(options.CleanWord2000);
    }
}
