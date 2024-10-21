using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    internal class CasesSnapshotTestHelper
    {
        private Document? _tidyDocument;

        private string _casesPath;
        private string _expectsPath;

        private string? _inputFile;
        private string? _configFile;

        private string? _expectsContentFile;
        private string? _expectsWarningsFile;

        private string? _outputFile;

        internal CasesSnapshotTestHelper(string casePrefix)
        {
            var casesPaths = new string[] { "cases", $"{casePrefix}-cases" };
            _casesPath = Path.Combine(casesPaths);

            var expectsPaths = new string[] { "cases", $"{casePrefix}-expects" };
            _expectsPath = Path.Combine(expectsPaths);
        }

        internal CasesSnapshotTestHelper ForCase(string caseNumber)
        {
            var caseName = $"case-{caseNumber}";

            var inputFile = Path.Combine(_casesPath, $"{caseName}@0.html");
            if( !File.Exists(inputFile))
            {
                throw new FileNotFoundException(inputFile);
            }
            _inputFile = inputFile;

            var configFile = Path.Combine(_casesPath, $"{caseName}.conf");
            if (!File.Exists(configFile))
            {
                throw new FileNotFoundException(configFile);
            }
            _configFile = configFile;

            var expectsContentFile = Path.Combine(_expectsPath, $"{caseName}.html");
            if (!File.Exists(expectsContentFile))
            {
                throw new FileNotFoundException(expectsContentFile);
            }
            _expectsContentFile = expectsContentFile;

            var expectsWarningsFile = Path.Combine(_expectsPath, $"{caseName}.txt");
            if (!File.Exists(expectsWarningsFile))
            {
                throw new FileNotFoundException(expectsWarningsFile);
            }
            _expectsWarningsFile = expectsWarningsFile;

            return this;
        }

        internal CasesSnapshotTestHelper LoadDocument(out Document tidyDocument)
        {
            _tidyDocument = Document.FromFile(_inputFile);
            tidyDocument = _tidyDocument;
            return this;
        }

        internal DocumentStatuses LoadConfig()
        {
            return _tidyDocument is null 
                ? throw new InvalidOperationException()
                : _tidyDocument.LoadConfig(_configFile);
        }

        internal DocumentStatuses ToFile()
        {
            _outputFile = Path.GetTempFileName();

            return _tidyDocument is null 
                ? throw new InvalidOperationException()
                : _tidyDocument.ToFile(_outputFile);
        }


        internal bool AreEqualOutput()
        {
            if (!File.Exists(_outputFile))
            {
                throw new FileNotFoundException(_outputFile);
            }

            if(_expectsContentFile is null) throw new InvalidOperationException("Call ForCase first");

            var expectedContent = File.ReadAllText(_expectsContentFile);
            var receivedContent = File.ReadAllText(_outputFile);
            
            File.Delete(_outputFile);

            return receivedContent == expectedContent;
        }        
    }
}
