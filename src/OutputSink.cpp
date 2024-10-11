#include "OutputSink.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
    private delegate void TidyPutByteDelegate(void* sinkData, byte bt);

    OutputSink::OutputSink(Stream ^ stream)
    {
        ArgumentNullException::ThrowIfNull(stream, "stream");
        _stream = stream;

        auto putByteFnPtr = Marshal::GetFunctionPointerForDelegate(gcnew TidyPutByteDelegate(this, &OutputSink::OnPutByte));

        _tidyOutputSink = new TidyOutputSink();
        _tidyOutputSink->sinkData = nullptr;
        _tidyOutputSink->putByte = static_cast<TidyPutByteFunc>(putByteFnPtr.ToPointer());        
    }

    OutputSink::~OutputSink()
    {
        if (_disposed) return;

        //Dispose managed objects here

        this->!OutputSink();
        _disposed = true;
    }

    OutputSink::!OutputSink()
    {
        //Free unmanaged objects here

        delete _tidyOutputSink;
    }

    void OutputSink::OnPutByte(void *sinkData, byte bt)
    {
        _stream->WriteByte(bt);
    }
}