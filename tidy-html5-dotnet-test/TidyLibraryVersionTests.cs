using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    public class TidyLibraryVersionTests
    {
        [Fact]
        public void Get_LibraryVersion_must_return_5_8_0()
        {
            Assert.Equal("5.8.0", Tidy.LibraryVersion);
        }

        [Fact]
        public void Get_LibraryVersion_must_match_assembly_version()
        {
            var assemblyVersion = typeof(Tidy).Assembly.GetName().Version;
            var semanticVersion = assemblyVersion?.ToString(3);

            Assert.Equal(Tidy.LibraryVersion, semanticVersion);
        }
    }
}
