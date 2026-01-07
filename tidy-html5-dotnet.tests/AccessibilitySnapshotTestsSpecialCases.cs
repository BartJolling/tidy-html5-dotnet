using System.Diagnostics;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;


// TODO : delete once not needed anymore
public class AccessibilitySnapshotTestsSpecialCases
{
    private readonly CasesSnapshotTestHelper _snapshotTestHelper;

    public AccessibilitySnapshotTestsSpecialCases()
    {
        _snapshotTestHelper = new CasesSnapshotTestHelper("access");
    }
    /*
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

        Assert.NotNull(_snapshotTestHelper.ExpectedContent);
        Assert.NotNull(_snapshotTestHelper.ReceivedContent);
        Assert.Equal(_snapshotTestHelper.ExpectedContent, _snapshotTestHelper.ReceivedContent);

        Assert.NotNull(_snapshotTestHelper.ExpectedMessages);
        Assert.NotNull(_snapshotTestHelper.ReceivedMessages);
        Assert.Equal(_snapshotTestHelper.ExpectedMessages, _snapshotTestHelper.ReceivedMessages);
    }
    
    [Fact]
    public void AccessCase_1_1_1_2()
    {
        var configStatus = _snapshotTestHelper
            .ForCase("1_1_1_2")
            .LoadDocument(out Document tidyDocument)
            .LoadConfig();

        Assert.Equal(DocumentStatuses.Success, configStatus);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        var diagStatus = tidyDocument.RunDiagnostics();
        Assert.Equal(DocumentStatuses.Warnings, diagStatus);

        Assert.NotNull(_snapshotTestHelper.ExpectedContent);
        Assert.NotNull(_snapshotTestHelper.ReceivedContent);
        Assert.Equal(_snapshotTestHelper.ExpectedContent, _snapshotTestHelper.ReceivedContent);

        Assert.NotNull(_snapshotTestHelper.ExpectedMessages);
        Assert.NotNull(_snapshotTestHelper.ReceivedMessages);
        Assert.Equal(_snapshotTestHelper.ExpectedMessages, _snapshotTestHelper.ReceivedMessages);
    }*/
}
