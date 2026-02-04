#pragma once

#include "tidy.h"

using namespace System::IO;
using namespace System::Runtime::InteropServices;

namespace TidyHtml5Dotnet
{
	private delegate void TidyPutByteDelegate(void* sinkData, byte bt);

	public ref class StreamSink
	{
    public:
		StreamSink(Stream^ stream);
		~StreamSink();
		!StreamSink();

	private:
		// root the lifetime of delegate and stream in the StreamSink lifecycle
		TidyPutByteDelegate^ _putByteDelegate;
		Stream^ _stream;
        TidyOutputSink* _tidyOutputSink;
		GCHandle _handle;

        void OnPutByte(void* sinkData, byte bt);

        bool _disposed = false;

	public:
		property TidyOutputSink* TidyOutSink
		{
			TidyOutputSink* get() { return _tidyOutputSink; }
		};        
    };
}