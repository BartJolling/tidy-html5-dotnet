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
        _snapshotTestHelper.ForCase("1_1_1_1");

        var tidyDocument = Document.FromFile(_snapshotTestHelper.InputFile);
        var configStatus = tidyDocument.LoadConfig(_snapshotTestHelper.ConfigFile);
        Assert.Equal(DocumentStatuses.Success, configStatus);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        string outputFile = Path.GetTempFileName();
        try
        {            
            var saveStatus = tidyDocument.ToFile(outputFile);
            Assert.Equal(DocumentStatuses.Warnings, saveStatus);
            Assert.True(_snapshotTestHelper.AreEqualContent(outputFile));
        }
        finally
        {
            File.Delete(outputFile);
        }
    }
}
