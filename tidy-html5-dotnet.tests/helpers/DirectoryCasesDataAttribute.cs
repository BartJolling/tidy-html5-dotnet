namespace tidy_html5_dotnet_test.helpers;

using System.Reflection;
using TidyHtml5Dotnet;
using Xunit.Sdk;

public sealed class DirectoryCasesDataAttribute : DataAttribute
{
    private readonly string _casePrefix;

    public DirectoryCasesDataAttribute(string casePrefix)
    {
        _casePrefix = casePrefix;
    }

    public override IEnumerable<object[]> GetData(MethodInfo testMethod)
    {
        var baseDir = AppContext.BaseDirectory;

        var casesPath = Path.Combine(baseDir, "cases", $"{_casePrefix}-cases");
        var expectsPath = Path.Combine(baseDir, "cases", $"{_casePrefix}-expects");

        if (!Directory.Exists(casesPath))
            throw new DirectoryNotFoundException(casesPath);
        if (!Directory.Exists(expectsPath))
            throw new DirectoryNotFoundException(expectsPath);

        var files = Directory
            .EnumerateFiles(casesPath, "case-*.xml")
            .Concat(Directory.EnumerateFiles(casesPath, "case-*.html"));

        foreach (var inputFilePath in files)
        {
            var fileName = Path.GetFileName(inputFilePath); 
            
            // Must contain @
            // TODO: check if the 0,1,2 after the @ have a meaning
            var atIndex = fileName.IndexOf('@');
            if (atIndex < 0) continue;

            var caseNumber = fileName["case-".Length..atIndex];

            // Expected files
            var expectedContentFile = Path.Combine(expectsPath, $"case-{caseNumber}.html");
            var expectedMessagesFile = Path.Combine(expectsPath, $"case-{caseNumber}.txt");

            // Require expects to exist
            if (!File.Exists(expectedContentFile) || !File.Exists(expectedMessagesFile))
                continue;

            // Config: try case-specific first, otherwise fallback to config_default.conf
            var caseConfigFile = Path.Combine(casesPath, $"case-{caseNumber}.conf");
            var defaultConfigFile = Path.Combine(casesPath, "config_default.conf");

            string configFilePath;
            if (File.Exists(caseConfigFile))
                configFilePath = caseConfigFile;
            else if (File.Exists(defaultConfigFile))
                configFilePath = defaultConfigFile;
            else
                continue; // skip only if both are missing

            var expectedContent = File.ReadAllText(expectedContentFile);
            var expectedMessages = File.ReadAllLines(expectedMessagesFile)
                .Where(l => !string.IsNullOrWhiteSpace(l))
                .Select(l => l.Trim())
                .ToList()
                .AsReadOnly();

            var cleanupStatus = expectedMessages.Count > 1 ? DocumentStatuses.Warnings : DocumentStatuses.Success;

            yield return new object[]
            {
                new CaseData(
                    caseNumber,
                    inputFilePath,
                    configFilePath,
                    expectedContent,
                    expectedMessages,
                    cleanupStatus,
                    cleanupStatus
                )
            };
        }
    }
}
