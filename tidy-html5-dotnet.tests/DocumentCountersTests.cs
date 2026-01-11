using TidyHtml5Dotnet;
using Xunit.Abstractions;

namespace tidy_html5_dotnet_test;

public class DocumentCountersTests
{
    private readonly ITestOutputHelper _output;
    private readonly List<FeedbackMessage> _tidyMessages = [];

    public DocumentCountersTests(ITestOutputHelper output)
    {
        _output = output;
        _tidyMessages.Clear();
    }

    [Fact]
    public void Counters_should_be_zero_on_clean_status()
    {
        // Arrange
        var htmlString = "<!DOCTYPE html><html><head><title>Title</title></head><body><h1>Header</h1></body></html>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;
            _tidyMessages.Add(message);
        };

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Success, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Single(_tidyMessages);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(0u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = _tidyMessages.Single(m => m.Key == "STRING_NO_ERRORS").Output;
        Assert.Equal("No warnings or errors were found.", dialogueSummary);
    }

    [Fact]
    public void WarningCounter_should_be_non_zero_on_warning_status()
    {
        // Arrange
        var htmlString = "<body><h1>Title</h1></body>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;
            _tidyMessages.Add(message);
        };

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(3, _tidyMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(2u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = _tidyMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 2 warnings and 0 errors!", dialogueSummary);
    }

    [Fact]
    public void ErrorCounter_should_be_non_zero_on_error_status()
    {
        // Arrange
        var htmlString = "<p>test</i><bogustag>bogus</bogustag>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;
            _tidyMessages.Add(message);
        };

        // Act
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Errors, status);
        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine($"{message.Level}: {message}" );
        }

        Assert.Equal(9, _tidyMessages.Count);
        Assert.Equal(1u, tidyDocument.ErrorCount);
        Assert.Equal(6u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = _tidyMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 6 warnings and 1 error!", dialogueSummary);
    }

    [Fact]
    public void AccessWarningCounter_should_be_zero_on_checklevel_classic()
    {
        // Arrange
        var htmlString = "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2//EN\">\r\n<html><head><title>Title</title></head>\r\n<body>\r\n\r\n<p><img src=\"img.png\"></p>\r\n\r\n</body></html>";
        using var tidyDocument = new Document(htmlString);       
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;
            _tidyMessages.Add(message);
        };

        // Act
        tidyDocument.DiagnosticOptions.AccessibilityCheckLevel = AccessibilityCheckLevels.TidyClassic;
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine($"{message.Level}: {message}" );
        }

        Assert.Equal(4, _tidyMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(1u, tidyDocument.WarningCount);
        Assert.Equal(0u, tidyDocument.AccessWarningCount);

        var dialogueSummary = _tidyMessages.Single(m => m.Key == "STRING_ERROR_COUNT").Output;
        Assert.Equal("Tidy found 1 warning and 0 errors!", dialogueSummary);
    }

    [Fact]
    public void AccessWarningCounter_should_be_non_zero_on_checklevel_priority3()
    {
        // Arrange
        var htmlString = "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2//EN\">\r\n<html><head><title>Title</title></head>\r\n<body>\r\n\r\n<p><img src=\"img.png\"></p>\r\n\r\n</body></html>";
        using var tidyDocument = new Document(htmlString);
        Assert.NotNull(tidyDocument);

        tidyDocument.FeedbackMessagesCallback = message =>
        {
            if (message.Level == ReportLevel.Info || message.Level == ReportLevel.DialogueInfo)
                return;
            _tidyMessages.Add(message);
        };

        // Act
        tidyDocument.DiagnosticOptions.AccessibilityCheckLevel = AccessibilityCheckLevels.Priority3;
        var status = tidyDocument.CleanAndRepair();

        // Assert
        Assert.Equal(DocumentStatuses.Warnings, status);

        _output.WriteLine(tidyDocument.ToString());

        foreach (var message in _tidyMessages)
        {
            _output.WriteLine($"{message.Level}: {message}");
        }

        Assert.Equal(7, _tidyMessages.Count);
        Assert.Equal(0u, tidyDocument.ErrorCount);
        Assert.Equal(0u, tidyDocument.WarningCount); // warning count moved to access warning counter
        Assert.Equal(6u, tidyDocument.AccessWarningCount);

        var dialogueSummary = _tidyMessages.Single(m => m.Key == "STRING_NO_ERRORS").Output;
        Assert.Equal("No warnings or errors were found.", dialogueSummary);
    }
}
