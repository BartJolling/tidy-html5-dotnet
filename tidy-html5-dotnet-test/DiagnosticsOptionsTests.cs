using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    public class DiagnosticsOptionsTests
    {
        [Fact]
        public void AccessibilityCheckLevel_property_should_Set_and_Get()
        {
            var document = new Document();
            Assert.Equal(AccessibilityCheckLevels.TidyClassic, document.Diagnostics.AccessibilityCheckLevel);

            document.Diagnostics.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority1;
            Assert.Equal(AccessibilityCheckLevels.Priority1, document.Diagnostics.AccessibilityCheckLevel);

            document.Diagnostics.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority2;
            Assert.Equal(AccessibilityCheckLevels.Priority2, document.Diagnostics.AccessibilityCheckLevel);

            document.Diagnostics.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority3;
            Assert.Equal(AccessibilityCheckLevels.Priority3, document.Diagnostics.AccessibilityCheckLevel);
        }
            
        [Fact]
        public void ShowErrors_property_should_Set_and_Get()
        {
            var document = new Document();
            Assert.Equal(6, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 0;
            Assert.Equal(0, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 1;
            Assert.Equal(1, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 2;
            Assert.Equal(2, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 3;
            Assert.Equal(3, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 4;
            Assert.Equal(4, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 5;
            Assert.Equal(5, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 6;
            Assert.Equal(6, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 7;
            Assert.Equal(7, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 8;
            Assert.Equal(8, document.Diagnostics.ShowErrors);

            document.Diagnostics.ShowErrors = 9;
            Assert.Equal(9, document.Diagnostics.ShowErrors);
        }

        [Fact]
        public void ShowInfo_property_should_Set_and_Get()
        {
            var document = new Document();
            Assert.True(document.Diagnostics.ShowInfo);

            document.Diagnostics.ShowInfo = false;
            Assert.False(document.Diagnostics.ShowInfo);

            document.Diagnostics.ShowInfo = true;
            Assert.True(document.Diagnostics.ShowInfo);
        }
    }
}
