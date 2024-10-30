using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    internal class CasesSnapshotTestHelper
    {
        private Document? _tidyDocument;
        private List<string>? _receivedMessages;

        private readonly string _casesPath;
        private readonly string _expectsPath;

        private string? _inputFile;
        private string? _configFile;

        private string? _expectedContentFile;
        private string? _expectedContent;
        private string? _expectedMessagesFile;
        private List<string>? _expectedMessages;

        private string? _receivedContent;

        internal CasesSnapshotTestHelper(string casePrefix)
        {
            var casesPaths = new string[] { "cases", $"{casePrefix}-cases" };
            _casesPath = Path.Combine(casesPaths);

            var expectsPaths = new string[] { "cases", $"{casePrefix}-expects" };
            _expectsPath = Path.Combine(expectsPaths);
        }

        internal CasesSnapshotTestHelper ForCase(string caseNumber)
        {
            //reset previous case
            _expectedContentFile = null;
            _expectedContent = null;
            _receivedContent = null;
            _expectedMessagesFile = null;
            _expectedMessages = null;
            _receivedMessages = null;

            //initialize current case
            var caseName = $"case-{caseNumber}";

            var inputFile = Path.Combine(_casesPath, $"{caseName}@0.html");
            if (!File.Exists(inputFile))
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
            _expectedContentFile = expectsContentFile;

            var expectsWarningsFile = Path.Combine(_expectsPath, $"{caseName}.txt");
            if (!File.Exists(expectsWarningsFile))
            {
                throw new FileNotFoundException(expectsWarningsFile);
            }
            _expectedMessagesFile = expectsWarningsFile;

            return this;
        }

        internal CasesSnapshotTestHelper LoadDocument(out Document tidyDocument)
        {
            _tidyDocument = Document.FromFile(_inputFile);

            tidyDocument = _tidyDocument;
            tidyDocument.FeedbackMessagesCallback = message => AddTidyMessage(message);

            return this;
        }

        private void AddTidyMessage(FeedbackMessage message)
        {
            if (message.Key == "STRING_HELLO_ACCESS") return;
            if (message.Key == "STRING_CONTENT_LOOKS") return;

            _receivedMessages ??= [];
            _receivedMessages.Add(message.Output.Trim());
        }

        internal DocumentStatuses LoadConfig()
        {
            return _tidyDocument is null
                ? throw new InvalidOperationException()
                : _tidyDocument.LoadConfig(_configFile);
        }

        internal string? ExpectedContent
        {
            get
            {
                if (_expectedContent is null && _expectedContentFile is not null)
                {
                    _expectedContent = File.ReadAllText(_expectedContentFile);
                }
                return _expectedContent;
            }
        }

        internal string? ReceivedContent
        {
            get
            {
                if (_receivedContent is null && _tidyDocument is not null)
                {
                    _receivedContent = _tidyDocument.ToString();
                }
                return _receivedContent;
            }
        }

        internal List<string>? ExpectedMessages
        {
            get
            {
                if (_expectedMessages is null && _expectedMessagesFile is not null)
                {
                    _expectedMessages = File.ReadAllLines(_expectedMessagesFile)
                           .Where(line => !string.IsNullOrWhiteSpace(line))
                           .Select(line => line.Trim())
                           .ToList();
                }
                return _expectedMessages;
            }
        }

        internal List<string>? ReceivedMessages
        {
            get { return _receivedMessages; }
        }
    }
}
