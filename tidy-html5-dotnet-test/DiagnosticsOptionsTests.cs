using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class DiagnosticsOptionsTests
{
    [Fact]
    public void AccessibilityCheckLevel_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DiagnosticOptions;
        Assert.NotNull(options);

        Assert.Equal(AccessibilityCheckLevels.TidyClassic, options.AccessibilityCheckLevel);

        options.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority1;
        Assert.Equal(AccessibilityCheckLevels.Priority1, options.AccessibilityCheckLevel);

        options.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority2;
        Assert.Equal(AccessibilityCheckLevels.Priority2, options.AccessibilityCheckLevel);

        options.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority3;
        Assert.Equal(AccessibilityCheckLevels.Priority3, options.AccessibilityCheckLevel);
    }

    [Fact]
    public void ForceOutput_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DiagnosticOptions;
        Assert.NotNull(options);

        Assert.False(options.ForceOutput);

        options.ForceOutput = true;
        Assert.True(options.ForceOutput);

        options.ForceOutput = false;
        Assert.False(options.ForceOutput);
    }

    [Fact]
    public void ShowMetaChange_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DiagnosticOptions;
        Assert.NotNull(options);

        Assert.False(options.ShowMetaChange);

        options.ShowMetaChange = true;
        Assert.True(options.ShowMetaChange);

        options.ShowMetaChange = false;
        Assert.False(options.ShowMetaChange);
    }

    [Fact]
    public void WarnProprietaryAttributes_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.DiagnosticOptions;
        Assert.NotNull(options);

        Assert.True(options.WarnProprietaryAttributes);

        options.WarnProprietaryAttributes = false;
        Assert.False(options.WarnProprietaryAttributes);

        options.WarnProprietaryAttributes = true;
        Assert.True(options.WarnProprietaryAttributes);
    }
}
