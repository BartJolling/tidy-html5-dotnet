using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class AccessibilitySnapshotTests
{
    private CasesSnapshotTestHelper _snapshotTestHelper;

    public AccessibilitySnapshotTests() 
    {
        _snapshotTestHelper = new CasesSnapshotTestHelper("access");
    }

    [Fact]
    public void AccessCase_1_1_1_1()
    {
        var configStatus = _snapshotTestHelper
            .ForCase("1_1_1_1")
            .LoadDocument(out Document tidyDocument)
            .LoadConfig();

        Assert.Equal(DocumentStatuses.Success, configStatus);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        var saveStatus = _snapshotTestHelper.ToFile();
        Assert.Equal(DocumentStatuses.Warnings, saveStatus);

        Assert.True(_snapshotTestHelper.AreEqualOutput());
    }
}
