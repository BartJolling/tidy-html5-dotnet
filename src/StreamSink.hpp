#pragma once

#include "tidy.h"

using namespace System::IO;

namespace TidyHtml5Dotnet
{
	public ref class StreamSink
	{
    public:
		StreamSink(Stream^ stream);
		~StreamSink();
		!StreamSink();

	private:
		Stream^ _stream;
        TidyOutputSink* _tidyOutputSink;

        void OnPutByte(void* sinkData, byte bt);

        bool _disposed = false;

	public:
		property TidyOutputSink* TidyOutSink
		{
			TidyOutputSink* get() { return _tidyOutputSink; }
		};        
    };
}