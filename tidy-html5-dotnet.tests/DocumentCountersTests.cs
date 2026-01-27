using System.Text;
using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DocumentCountersTests(ITestOutputHelper output)
{
    private readonly ITestOutputHelper _output = output;

    private static IncludeInReport ExcludeInfoMessages(FeedbackMessage message)
    {
        return (message.Level == ReportLevel.Info ||
                message.Level == ReportLevel.DialogueInfo)
            ? IncludeInReport.No
            : IncludeInReport.Yes;
    }

    [Fact]
    public void Counters_should_be_zero_on_clean_status()
    {
        // Arrange
        var htmlString = "<!DOCTYPE html><html><head><title>Title</title></head><body><h1>Header</h1></body></html>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage = ExcludeInfoMessages;

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Success, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Single(tidyDocument.DiagnosticMessages);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(0u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = tidyDocument.DiagnosticMessages.Single(m => m.Key == "STRING_NO_ERRORS").Output;
        Assert.Equal("No warnings or errors were found.", dialogueSummary);
    }

    [Fact]
    public void WarningCounter_should_be_non_zero_on_warning_status()
    {
        // Arrange
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage = ExcludeInfoMessages;

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(3, tidyDocument.DiagnosticMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(2u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = tidyDocument.DiagnosticMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 2 warnings and 0 errors!", dialogueSummary);
    }

    [Fact]
    public void ErrorCounter_should_be_non_zero_on_error_status()
    {
        // Arrange
        var htmlString = "<p>test</i><bogustag>bogus</bogustag>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage = ExcludeInfoMessages;

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Errors, status);
        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(9, tidyDocument.DiagnosticMessages.Count);
        Assert.Equal(1u, tidyDocument.ErrorCount);
        Assert.Equal(6u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        Assert.NotEmpty(tidyDocument.DiagnosticMessages);

        var dialogueSummary = tidyDocument.DiagnosticMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 6 warnings and 1 error!", dialogueSummary);
    }

    [Fact]
    public void AccessWarningCounter_should_be_zero_on_checklevel_classic()
    {
        // Arrange
        var htmlString = "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2//EN\">\r\n<html><head><title>Title</title></head>\r\n<body>\r\n\r\n<p><img src=\"img.png\"></p>\r\n\r\n</body></html>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage = ExcludeInfoMessages;

        // Act
        tidyDocument.DiagnosticOptions.AccessibilityCheckLevel = AccessibilityCheckLevels.TidyClassic;
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(4, tidyDocument.DiagnosticMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(1u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = tidyDocument.DiagnosticMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 1 warning and 0 errors!", dialogueSummary);
    }

    [Fact]
    public void AccessWarningCounter_should_be_non_zero_on_checklevel_priority3()
    {
        // Arrange
        var reportStream = new MemoryStream();
        var htmlString = "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2//EN\">\r\n<html><head><title>Title</title></head>\r\n<body>\r\n\r\n<p><img src=\"img.png\"></p>\r\n\r\n</body></html>";
        using var tidyDocument = new Document(htmlString).WithReportStream(reportStream);
        Assert.NotNull(tidyDocument);

        tidyDocument.OnReceiveDiagnosticMessage = ExcludeInfoMessages;

        // Act
        tidyDocument.DiagnosticOptions.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority3;
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);
        var output = tidyDocument.ToString();
        Assert.NotEmpty(output);
        _output.WriteLine(output);

        Assert.NotEmpty(tidyDocument.DiagnosticMessages);
        foreach (var message in tidyDocument.DiagnosticMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(7, tidyDocument.DiagnosticMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(0u, tidyDocument.WarningCount); // warning count moved to access warning counter
        Assert.Equal(6u, tidyDocument.AccessWarningCount);

        var dialogueSummary = tidyDocument.DiagnosticMessages.Single(m => m.Key == "STRING_NO_ERRORS").Output;
        Assert.Equal("No warnings or errors were found.", dialogueSummary);
    }
}
