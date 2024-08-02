using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class FileOptionsTests
{
    [Fact]
    public void ErrorFile_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.FileOptions;
        Assert.NotNull(options);

        Assert.Null(options.ErrorFile);

        options.ErrorFile = new FileInfo(@"c:\error.txt");
        Assert.NotNull(options.ErrorFile);
        Assert.Equal(@"c:\error.txt", options.ErrorFile.FullName);

        options.ErrorFile = null;
        Assert.Null(options.ErrorFile);
    }

    [Fact]
    public void KeepTime_sets_option_AnchorAsNamee()
    {
        var document = new Document();

        var options = document.FileOptions;
        Assert.NotNull(options);

        Assert.False(options.KeepTime);

        options.KeepTime = true;
        Assert.True(options.KeepTime);

        options.KeepTime = false;
        Assert.False(options.KeepTime);
    }

    [Fact]
    public void OutputFile_property_should_Set_and_Get()
    {
        var document = new Document();

        var options = document.FileOptions;
        Assert.NotNull(options);

        Assert.Null(options.OutputFile);

        options.OutputFile = new FileInfo(@"c:\output.txt");
        Assert.NotNull(options.OutputFile);
        Assert.Equal(@"c:\output.txt", options.OutputFile.FullName);

        options.OutputFile = null;
        Assert.Null(options.OutputFile);
    }

    [Fact]
    public void WriteBack_sets_option_AnchorAsNamee()
    {
        var document = new Document();

        var options = document.FileOptions;
        Assert.NotNull(options);

        Assert.False(options.WriteBack);

        options.WriteBack = true;
        Assert.True(options.WriteBack);

        options.WriteBack = false;
        Assert.False(options.WriteBack);
    }
}