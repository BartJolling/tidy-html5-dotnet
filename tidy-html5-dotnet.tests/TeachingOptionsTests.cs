using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test
{
    public class TeachingOptionsTests
    {
        [Fact]
        public void NewBlockLevelTags_property_should_Set_and_Get()
        {
            var document = new Document();
            var options = document.TeachingOptions;
            Assert.NotNull(options);

            Assert.Empty(options.NewBlockLevelTags);

            options.NewBlockLevelTags = ["tagX", "tagY", "tagZ"];
            Assert.NotEmpty(options.NewBlockLevelTags);
            Assert.Equal(3, options.NewBlockLevelTags.Count());

            Assert.Equal("tagX", options.NewBlockLevelTags.ElementAt(0));
            Assert.Equal("tagY", options.NewBlockLevelTags.ElementAt(1));
            Assert.Equal("tagZ", options.NewBlockLevelTags.ElementAt(2));

            options.NewBlockLevelTags = ["element1", "element2"];
            Assert.NotEmpty(options.NewBlockLevelTags);
            Assert.Equal(2, options.NewBlockLevelTags.Count());

            Assert.Equal("element1", options.NewBlockLevelTags.First());
            Assert.Equal("element2", options.NewBlockLevelTags.Last());

            options.NewBlockLevelTags = [];
            Assert.Empty(options.NewBlockLevelTags);

            Assert.Throws<ArgumentNullException>(() => options.NewBlockLevelTags = null);
        }

        [Fact]
        public void NewEmptyTags_property_should_Set_and_Get()
        {
            var document = new Document();
            var options = document.TeachingOptions;
            Assert.NotNull(options);

            Assert.Empty(options.NewEmptyTags);

            options.NewEmptyTags = ["tagX", "tagY", "tagZ"];
            Assert.NotEmpty(options.NewEmptyTags);
            Assert.Equal(3, options.NewEmptyTags.Count());

            Assert.Equal("tagX", options.NewEmptyTags.ElementAt(0));
            Assert.Equal("tagY", options.NewEmptyTags.ElementAt(1));
            Assert.Equal("tagZ", options.NewEmptyTags.ElementAt(2));

            options.NewEmptyTags = ["element1", "element2"];
            Assert.NotEmpty(options.NewEmptyTags);
            Assert.Equal(2, options.NewEmptyTags.Count());

            Assert.Equal("element1", options.NewEmptyTags.First());
            Assert.Equal("element2", options.NewEmptyTags.Last());

            options.NewEmptyTags = [];
            Assert.Empty(options.NewEmptyTags);

            Assert.Throws<ArgumentNullException>(() => options.NewEmptyTags = null);
        }

        [Fact]
        public void NewInlineTags_property_should_Set_and_Get()
        {
            var document = new Document();
            var options = document.TeachingOptions;
            Assert.NotNull(options);

            Assert.Empty(options.NewInlineTags);

            options.NewInlineTags = ["tagX", "tagY", "tagZ"];
            Assert.NotEmpty(options.NewInlineTags);
            Assert.Equal(3, options.NewInlineTags.Count());

            Assert.Equal("tagX", options.NewInlineTags.ElementAt(0));
            Assert.Equal("tagY", options.NewInlineTags.ElementAt(1));
            Assert.Equal("tagZ", options.NewInlineTags.ElementAt(2));

            options.NewInlineTags = ["element1", "element2"];
            Assert.NotEmpty(options.NewInlineTags);
            Assert.Equal(2, options.NewInlineTags.Count());

            Assert.Equal("element1", options.NewInlineTags.First());
            Assert.Equal("element2", options.NewInlineTags.Last());

            options.NewInlineTags = [];
            Assert.Empty(options.NewInlineTags);

            Assert.Throws<ArgumentNullException>(() => options.NewInlineTags = null);
        }

        [Fact]
        public void NewPreTags_property_should_Set_and_Get()
        {
            var document = new Document();
            var options = document.TeachingOptions;
            Assert.NotNull(options);

            Assert.Empty(options.NewPreTags);

            options.NewPreTags = ["tagX", "tagY", "tagZ"];
            Assert.NotEmpty(options.NewPreTags);
            Assert.Equal(3, options.NewPreTags.Count());

            Assert.Equal("tagX", options.NewPreTags.ElementAt(0));
            Assert.Equal("tagY", options.NewPreTags.ElementAt(1));
            Assert.Equal("tagZ", options.NewPreTags.ElementAt(2));

            options.NewPreTags = ["element1", "element2"];
            Assert.NotEmpty(options.NewPreTags);
            Assert.Equal(2, options.NewPreTags.Count());

            Assert.Equal("element1", options.NewPreTags.First());
            Assert.Equal("element2", options.NewPreTags.Last());

            options.NewPreTags = [];
            Assert.Empty(options.NewPreTags);

            Assert.Throws<ArgumentNullException>(() => options.NewPreTags = null);
        }
    }
}