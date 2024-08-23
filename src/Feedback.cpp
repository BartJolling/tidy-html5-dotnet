#include "Feedback.hpp"

using namespace System;

namespace TidyHtml5Dotnet
{
    Feedback::Feedback(TidyMessage tmessage)
    {
        if( tmessage == nullptr) 
            throw gcnew ArgumentNullException("tmessage", "Cannot create Message from null TidyMessage" );
        
        _tmessage = tmessage;
        _key = gcnew String(tidyGetMessageKey(tmessage));
		_output = gcnew String(tidyGetMessageOutput(tmessage));
    };

    String^ Feedback::Key::get()
    {
        return _key;
    } 

	String^ Feedback::Output::get()
    {
        return _output;
    } 
}