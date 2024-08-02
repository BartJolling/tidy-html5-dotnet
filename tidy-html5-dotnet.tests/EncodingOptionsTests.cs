using TidyHtml5Dotnet;

namespace tidy_html5_dotnet_test;

public class EncodingOptionsTests
{
    [Fact]
    public void CharacterEncoding_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        Assert.Equal(Encodings.Utf8, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Ascii;
        Assert.Equal(Encodings.Ascii, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Latin0;
        Assert.Equal(Encodings.Latin0, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Utf8;
        Assert.Equal(Encodings.Utf8, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Iso2022;
        Assert.Equal(Encodings.Iso2022, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.MacRoman;
        Assert.Equal(Encodings.MacRoman, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Win1252;
        Assert.Equal(Encodings.Win1252, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Ibm858;
        Assert.Equal(Encodings.Ibm858, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Utf16LittleEndian;
        Assert.Equal(Encodings.Utf16LittleEndian, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Utf16BigEndian;
        Assert.Equal(Encodings.Utf16BigEndian, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Utf16;
        Assert.Equal(Encodings.Utf16, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.Big5;
        Assert.Equal(Encodings.Big5, options.CharacterEncoding);

        options.CharacterEncoding = Encodings.ShiftJIS;
        Assert.Equal(Encodings.ShiftJIS, options.CharacterEncoding);
    }

    [Fact]
    public void InputCharacterEncoding_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        Assert.Equal(Encodings.Utf8, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Ascii;
        Assert.Equal(Encodings.Ascii, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Latin0;
        Assert.Equal(Encodings.Latin0, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Utf8;
        Assert.Equal(Encodings.Utf8, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Iso2022;
        Assert.Equal(Encodings.Iso2022, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.MacRoman;
        Assert.Equal(Encodings.MacRoman, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Win1252;
        Assert.Equal(Encodings.Win1252, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Ibm858;
        Assert.Equal(Encodings.Ibm858, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Utf16LittleEndian;
        Assert.Equal(Encodings.Utf16LittleEndian, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Utf16BigEndian;
        Assert.Equal(Encodings.Utf16BigEndian, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Utf16;
        Assert.Equal(Encodings.Utf16, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.Big5;
        Assert.Equal(Encodings.Big5, options.InputCharacterEncoding);

        options.InputCharacterEncoding = Encodings.ShiftJIS;
        Assert.Equal(Encodings.ShiftJIS, options.InputCharacterEncoding);
    }

    [Fact]
    public void LineEnding_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        Assert.Equal(LineEndings.CarriageReturnLineFeed, options.LineEnding);

        options.LineEnding = LineEndings.LineFeed;
        Assert.Equal(LineEndings.LineFeed, options.LineEnding);

        options.LineEnding = LineEndings.CarriageReturnLineFeed;
        Assert.Equal(LineEndings.CarriageReturnLineFeed, options.LineEnding);

        options.LineEnding = LineEndings.CarriageReturn;
        Assert.Equal(LineEndings.CarriageReturn, options.LineEnding);
    }

    [Fact]
    public void OuputByteOrderMark_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        Assert.Null(options.OutputByteOrderMark);

        options.OutputByteOrderMark = true;
        Assert.True(options.OutputByteOrderMark);

        options.OutputByteOrderMark = false;
        Assert.False(options.OutputByteOrderMark);

        options.OutputByteOrderMark = null;
        Assert.Null(options.OutputByteOrderMark);
    }

    [Fact]
    public void OutputCharacterEncoding_property_should_Set_and_Get()
    {
        var document = new Document();
        var options = document.EncodingOptions;
        Assert.NotNull(options);

        Assert.Equal(Encodings.Utf8, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Ascii;
        Assert.Equal(Encodings.Ascii, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Latin0;
        Assert.Equal(Encodings.Latin0, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Utf8;
        Assert.Equal(Encodings.Utf8, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Iso2022;
        Assert.Equal(Encodings.Iso2022, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.MacRoman;
        Assert.Equal(Encodings.MacRoman, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Win1252;
        Assert.Equal(Encodings.Win1252, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Ibm858;
        Assert.Equal(Encodings.Ibm858, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Utf16LittleEndian;
        Assert.Equal(Encodings.Utf16LittleEndian, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Utf16BigEndian;
        Assert.Equal(Encodings.Utf16BigEndian, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Utf16;
        Assert.Equal(Encodings.Utf16, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.Big5;
        Assert.Equal(Encodings.Big5, options.OutputCharacterEncoding);

        options.OutputCharacterEncoding = Encodings.ShiftJIS;
        Assert.Equal(Encodings.ShiftJIS, options.OutputCharacterEncoding);
    }
}