using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class TidyReleaseDateTests
{
    [Fact]
    public void Get_ReleaseDate_must_return_2021_7_10()
    {
        var expectedReleaseDate = new DateTime(2021, 7, 10);
        Assert.Equal(expectedReleaseDate, Tidy.ReleaseDate);
    }
}
