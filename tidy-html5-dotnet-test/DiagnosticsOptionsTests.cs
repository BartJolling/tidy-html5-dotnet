using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

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
}
