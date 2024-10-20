using TidyHtml5Dotnet;
using VerifyTests;

namespace tidy_html5_dotnet_test;

public class DiagnosticOptionsAccessibilityTests
{
    [Fact]
    public void Case_1_1_1_1_must_succeed()
    {
        // Arrange
        var caseName = "case-1_1_1_1";
        var configFileName = @$"C:\Users\a98017094\Repos\tidy-html5-dotnet\regression_testing\cases\access-cases\{caseName}.conf";
        var inputFileName = @$"C:\Users\a98017094\Repos\tidy-html5-dotnet\regression_testing\cases\access-cases\{caseName}@0.html";
        var actualFileName = @$"C:\Users\a98017094\Repos\tidy-html5-dotnet\regression_testing\cases\access-expects\{caseName}.actual.html";
        var expectedFileName = @$"C:\Users\a98017094\Repos\tidy-html5-dotnet\regression_testing\cases\access-expects\{caseName}.html";
        var warningsFileName = @$"C:\Users\a98017094\Repos\tidy-html5-dotnet\regression_testing\cases\access-expects\{caseName}.txt";

        var expectedContent = File.ReadAllText(expectedFileName);
        var expectedWarnings = File.ReadAllLines(warningsFileName);

        // Act
        using var tidyDocument = Document.FromFile(inputFileName);
        Assert.NotNull(tidyDocument);

        var configStatus = tidyDocument.LoadConfig(configFileName);
        Assert.Equal(DocumentStatuses.Success, configStatus);

        var cleanStatus = tidyDocument.CleanAndRepair();
        Assert.Equal(DocumentStatuses.Warnings, cleanStatus);

        var saveStatus = tidyDocument.ToFile(actualFileName);
        Assert.Equal(DocumentStatuses.Warnings, saveStatus);

        // Assert
        var actualContent = File.ReadAllText(actualFileName);

        Assert.Equal(expectedContent, actualContent);        
    }
}