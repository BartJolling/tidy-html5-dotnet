using System.Text;
using TidyHtml5Dotnet;

namespace TidyHtml5DotnetTests
{
    public class DocumentTests
    {
        [Fact]
        public void Create_Document_Without_Parameters()
        {
            var tidyDocument = new Document();
            Assert.NotNull(tidyDocument);
        }

        [Fact]
        public void Create_Document_From_String()
        {
            var htmlString = "<body><h1>Title</body>";
            var tidyDocument = new Document(htmlString);
            Assert.NotNull(tidyDocument);
        }

        [Fact]
        public void Create_Document_From_Stream()
        {
            var htmlStream = new MemoryStream(Encoding.UTF8.GetBytes("<body><h1>Title</body>"));
            var tidyDocument = new Document(htmlStream);
            Assert.NotNull(tidyDocument);
        }
    }
}