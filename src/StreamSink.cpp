#include "StreamSink.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
    private delegate void TidyPutByteDelegate(void* sinkData, byte bt);

    StreamSink::StreamSink(Stream ^ stream)
    {
        ArgumentNullException::ThrowIfNull(stream, "stream");
        _stream = stream;

        auto putByteFnPtr = Marshal::GetFunctionPointerForDelegate(gcnew TidyPutByteDelegate(this, &StreamSink::OnPutByte));

        _tidyOutputSink = new TidyOutputSink();
        _tidyOutputSink->sinkData = nullptr;
        _tidyOutputSink->putByte = static_cast<TidyPutByteFunc>(putByteFnPtr.ToPointer());        
    }

    StreamSink::~StreamSink()
    {
        if (_disposed) return;

        //Dispose managed objects here

        this->!StreamSink();
        _disposed = true;
    }

    StreamSink::!StreamSink()
    {
        //Free unmanaged objects here

        delete _tidyOutputSink;
    }

    void StreamSink::OnPutByte(void *sinkData, byte bt)
    {
        _stream->WriteByte(bt);
    }
}