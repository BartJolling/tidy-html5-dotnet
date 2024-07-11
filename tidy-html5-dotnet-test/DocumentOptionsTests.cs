using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    public class DocumentOptionsTests
    {
        [Fact]
        public void AddXmlDeclaration_sets_option_TidyXmlDecl()
        {
            var document = new Document();

            document.Options.AddXmlDeclaration = true;
            Assert.True(document.Options.AddXmlDeclaration);

            document.Options.AddXmlDeclaration = false;
            Assert.False(document.Options.AddXmlDeclaration);
        }

        [Fact]
        public void AddXmlSpacePreserve_sets_option_TidyXmlSpace()
        {
            var document = new Document();

            document.Options.AddXmlSpacePreserve = true;
            Assert.True(document.Options.AddXmlSpacePreserve);

            document.Options.AddXmlSpacePreserve = false;
            Assert.False(document.Options.AddXmlSpacePreserve);
        }

        [Fact]
        public void DefaultAltText_sets_option_TidyAltText()
        {
            var document = new Document();
            Assert.Equal(String.Empty, document.Options.DefaultAltText);

            document.Options.DefaultAltText = "Default Alt Text";
            Assert.Equal("Default Alt Text", document.Options.DefaultAltText);
        }

        [Fact]
        public void AnchorAsName_sets_option_AnchorAsNamee()
        {
            var document = new Document();

            document.Options.AnchorAsName = true;
            Assert.True(document.Options.AnchorAsName);

            document.Options.AnchorAsName = false;
            Assert.False(document.Options.AnchorAsName);
        }

        [Fact]
        public void ChangeXmlProcessingInstructions_sets_option_TidyXmlPIs()
        {
            var document = new Document();

            document.Options.ChangeXmlProcessingInstructions = true;
            Assert.True(document.Options.ChangeXmlProcessingInstructions);

            document.Options.ChangeXmlProcessingInstructions = false;
            Assert.False(document.Options.ChangeXmlProcessingInstructions);
        }

        [Fact]
        public void MakeBare_sets_option_TidyMakeBare()
        {
            var document = new Document();

            document.Options.MakeBare = true;
            Assert.True(document.Options.MakeBare);

            document.Options.MakeBare = false;
            Assert.False(document.Options.MakeBare);
        }

        [Fact]
        public void MakeClean_sets_option_TidyMakeClean()
        {
            var document = new Document();

            document.Options.MakeClean = true;
            Assert.True(document.Options.MakeClean);

            document.Options.MakeClean = false;
            Assert.False(document.Options.MakeClean);
        }

        [Fact]
        public void CoerceEndTags_sets_option_TidyCoerceEndTags()
        {
            var document = new Document();

            document.Options.CoerceEndTags = true;
            Assert.True(document.Options.CoerceEndTags);

            document.Options.CoerceEndTags = false;
            Assert.False(document.Options.CoerceEndTags);
        }

        [Fact]
        public void CssPrefix_sets_option_TidyCSSPrefix()
        {
            var document = new Document();
            Assert.Equal("c", document.Options.CssPrefix);
            
            document.Options.CssPrefix = "css-prefix";            
            Assert.Equal("css-prefix", document.Options.CssPrefix);
        }

        [Fact]
        public void DecorateInferredUL_sets_option_TidyDecorateInferredUL()
        {
            var document = new Document();

            document.Options.DecorateInferredUL = true;
            Assert.True(document.Options.DecorateInferredUL);

            document.Options.DecorateInferredUL = false;
            Assert.False(document.Options.DecorateInferredUL);
        }

        [Fact]
        public void DocType_sets_option_TidyCSSPrefix()
        {
            var document = new Document();
            Assert.Equal(DocTypeModes.Auto, document.Options.DocTypeMode);

            document.Options.DocTypeMode = DocTypeModes.Html5;
            Assert.Equal(DocTypeModes.Html5, document.Options.DocTypeMode);

            document.Options.DocTypeMode = DocTypeModes.Omit;
            Assert.Equal(DocTypeModes.Omit, document.Options.DocTypeMode);

            document.Options.DocTypeMode = DocTypeModes.Strict;
            Assert.Equal(DocTypeModes.Strict, document.Options.DocTypeMode);

            document.Options.DocTypeMode = DocTypeModes.Loose;
            Assert.Equal(DocTypeModes.Loose, document.Options.DocTypeMode);

            document.Options.DocTypeMode = DocTypeModes.User;
            Assert.Equal(DocTypeModes.User, document.Options.DocTypeMode);
        }
    }
}
