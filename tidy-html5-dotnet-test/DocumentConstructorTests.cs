using System.Text;
using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    public class DocumentConstructorTests
    {
        [Fact]
        public void Create_Document_without_parameters_must_succeed()
        {
            var tidyDocument = new Document();
            Assert.NotNull(tidyDocument);
        }

        [Fact]
        public void Create_Document_from_String_must_succeed()
        {
            var htmlString = "<body><h1>Title</h1></body>";
            var tidyDocument = new Document(htmlString);
            Assert.NotNull(tidyDocument);
        }

        [Fact]
        public void Create_Document_from_Stream_must_succeed()
        {
            var htmlStream = new MemoryStream(Encoding.UTF8.GetBytes("<body><h1>Title</h1></body>"));
            var tidyDocument = new Document(htmlStream);
            Assert.NotNull(tidyDocument);
        }
    }
}