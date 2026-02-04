namespace tidy_html5_dotnet_test.helpers;

using System.Reflection;
using System.Threading.Tasks;
using TidyHtml5Dotnet;
using Xunit;
using Xunit.Sdk;
using Xunit.v3;

public sealed class DirectoryCasesDataAttribute(string casePrefix) : DataAttribute
{
    public override bool SupportsDiscoveryEnumeration() => true;

    public IEnumerable<TheoryDataRow<CaseData>> GetData(MethodInfo testMethod)
    {
        var baseDir = AppContext.BaseDirectory;

        var casesPath = Path.Combine(baseDir, "cases", $"{casePrefix}-cases");
        var expectsPath = Path.Combine(baseDir, "cases", $"{casePrefix}-expects");

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
            var expectedReport = File.ReadAllText(expectedMessagesFile);

            var cleanupStatus = "No warnings or errors were found.".Equals(expectedReport.Trim())
                ? DocumentStatuses.Success
                : DocumentStatuses.Warnings;

            yield return new TheoryDataRow<CaseData>(
                new CaseData(
                    caseNumber,
                    inputFilePath,
                    configFilePath,
                    expectedContent,
                    expectedReport,
                    cleanupStatus,
                    cleanupStatus
                )
             );
        }
    }

    public override ValueTask<IReadOnlyCollection<ITheoryDataRow>> GetData(MethodInfo testMethod, DisposalTracker disposalTracker)
    {
        return ValueTask.FromResult<IReadOnlyCollection<ITheoryDataRow>>(GetData(testMethod).ToList());
    }
}
