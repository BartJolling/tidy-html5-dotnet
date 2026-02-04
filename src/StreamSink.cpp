#include "StreamSink.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
    StreamSink::StreamSink(Stream ^ stream)
    {
        ArgumentNullException::ThrowIfNull(stream, "stream");
        _stream = stream;        

        _handle = GCHandle::Alloc(this);
        _putByteDelegate = gcnew TidyPutByteDelegate(this, &StreamSink::OnPutByte);
        auto putByteFnPtr = Marshal::GetFunctionPointerForDelegate(_putByteDelegate);

        _tidyOutputSink = new TidyOutputSink();
        _tidyOutputSink->sinkData = GCHandle::ToIntPtr(_handle).ToPointer();
        _tidyOutputSink->putByte = static_cast<TidyPutByteFunc>(putByteFnPtr.ToPointer());        
    }

    StreamSink::~StreamSink()
    {
        if (_disposed) return;

        // Release managed references early
        _putByteDelegate = nullptr;
        _stream = nullptr;

        this->!StreamSink();
        _disposed = true;
    }

    StreamSink::!StreamSink()
    {
        //Free unmanaged objects here
        if (_handle.IsAllocated)
            _handle.Free();

        delete _tidyOutputSink;
        _tidyOutputSink = nullptr;
    }

    void StreamSink::OnPutByte(void *sinkData, byte bt)
    {
        _stream->WriteByte(bt);
    }
}