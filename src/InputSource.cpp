#include "InputSource.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
    private delegate int TidyGetByteDelegate(void* source);
    private delegate void TidyUngetByteDelegate(void* sourceData, byte bt);
    private delegate bool TidyEOFDelegate(void* source);

	InputSource::InputSource(Stream^ stream)
	{
		ArgumentNullException::ThrowIfNull(stream, "stream");

        _stream = stream;

        auto getByteFnPtr = Marshal::GetFunctionPointerForDelegate(gcnew TidyGetByteDelegate(this, &InputSource::GetByte));
        auto ungetByteFnPtr = Marshal::GetFunctionPointerForDelegate(gcnew TidyUngetByteDelegate(this, &InputSource::UngetByte));
        auto isEofFnPtr = Marshal::GetFunctionPointerForDelegate(gcnew TidyEOFDelegate(this, &InputSource::IsEOF));

		_tidyInputSource = new TidyInputSource();
		_tidyInputSource->sourceData = nullptr;
        _tidyInputSource->getByte = static_cast<TidyGetByteFunc>(getByteFnPtr.ToPointer());
        _tidyInputSource->ungetByte = static_cast<TidyUngetByteFunc>(ungetByteFnPtr.ToPointer());
        _tidyInputSource->eof = static_cast<TidyEOFFunc>(isEofFnPtr.ToPointer());
	}

    InputSource::~InputSource()
    {
        if (_disposed) return;

        //Dispose managed objects here

        this->!InputSource();
        _disposed = true;
    }

    InputSource::!InputSource()
    {
        //Free unmanaged objects here
        delete _tidyInputSource;
    }

    int InputSource::GetByte(void* source)
    {
        return (byte)_stream->ReadByte();
    }

    void InputSource::UngetByte(void* source, byte byte)
    {
        if(_stream->Position > 0) _stream->Position--;
    }

    bool InputSource::IsEOF(void* source)
    {
        return (_stream->Position >= _stream->Length);
    }
}
