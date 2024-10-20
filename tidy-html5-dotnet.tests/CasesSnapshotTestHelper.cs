namespace tidy_html5_dotnet_test
{
    internal class CasesSnapshotTestHelper
    {
        private string _casesPath;
        private string _expectsPath;

        private string? _inputFile;
        private string? _configFile;

        private string? _expectsContentFile;
        private string? _expectsWarningsFile;

        public CasesSnapshotTestHelper(string casePrefix)
        {
            var casesPaths = new string[] { "cases", $"{casePrefix}-cases" };
            _casesPath = Path.Combine(casesPaths);

            var expectsPaths = new string[] { "cases", $"{casePrefix}-expects" };
            _expectsPath = Path.Combine(expectsPaths);
        }

        public CasesSnapshotTestHelper ForCase(string caseNumber)
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

        public string? InputFile
        {
            get { return _inputFile; }
        }

        public string? ConfigFile
        {
            get { return _configFile; }
        }

        public bool AreEqualContent(string outputfile)
        {
            if (!File.Exists(outputfile))
            {
                throw new FileNotFoundException(outputfile);
            }

            if(_expectsContentFile is null) throw new InvalidOperationException("Call1 ForCase first");

            var receivedContent = File.ReadAllText(outputfile);
            var expectedContent = File.ReadAllText(_expectsContentFile);

            return receivedContent == expectedContent;
        }
    }
}
