using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

/// <summary>
/// https://api.html-tidy.org/tidy/tidylib_api_5.8.0/tidy_quickref.html#DisplayHeader
/// </summary>
public class DisplayOptionsTests
{
    [Fact]
    public void GnuEmacs_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.False(options.GnuEmacs);

        options.GnuEmacs = true;
        Assert.True(options.GnuEmacs);

        options.GnuEmacs = false;
        Assert.False(options.GnuEmacs);
    }

    [Fact]
    public void Markup_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.True(options.Markup);

        options.Markup = false;
        Assert.False(options.Markup);

        options.Markup = true;
        Assert.True(options.Markup);
    }

    [Fact]
    public void Mute_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.Empty(options.Mute);

        options.Mute = "TidyMuteReports";
        Assert.Equal("TidyMuteReports", options.Mute);
    }

    [Fact]
    public void MuteId_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.False(options.MuteId);

        options.MuteId = true;
        Assert.True(options.MuteId);

        options.MuteId = false;
        Assert.False(options.MuteId);
    }

    [Fact]
    public void Quiet_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.False(options.Quiet);

        options.Quiet = true;
        Assert.True(options.Quiet);

        options.Quiet = false;
        Assert.False(options.Quiet);
    }

    [Fact]
    public void ShowBodyOnly_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.False(options.ShowBodyOnly);

        options.ShowBodyOnly = true;
        Assert.True(options.ShowBodyOnly);

        options.ShowBodyOnly = null;
        Assert.Null(options.ShowBodyOnly);
    }

    [Fact]
    public void ShowErrors_property_should_Set_and_Get()
    {
        var document = new Document();
        Assert.Equal(6, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 0;
        Assert.Equal(0, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 1;
        Assert.Equal(1, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 2;
        Assert.Equal(2, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 3;
        Assert.Equal(3, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 4;
        Assert.Equal(4, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 5;
        Assert.Equal(5, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 6;
        Assert.Equal(6, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 7;
        Assert.Equal(7, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 8;
        Assert.Equal(8, document.DisplayOptions.ShowErrors);

        document.DisplayOptions.ShowErrors = 9;
        Assert.Equal(9, document.DisplayOptions.ShowErrors);
    }

    [Fact]
    public void ShowInfo_property_should_Set_and_Get()
    {
        var document = new Document();
        Assert.True(document.DisplayOptions.ShowInfo);

        document.DisplayOptions.ShowInfo = false;
        Assert.False(document.DisplayOptions.ShowInfo);

        document.DisplayOptions.ShowInfo = true;
        Assert.True(document.DisplayOptions.ShowInfo);
    }

    [Fact]
    public void ShowWarnings_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DisplayOptions;
        Assert.NotNull(options);

        Assert.True(options.ShowWarnings);

        options.ShowWarnings = false;
        Assert.False(options.ShowWarnings);

        options.ShowWarnings = true;
        Assert.True(options.ShowWarnings);
    }
}
