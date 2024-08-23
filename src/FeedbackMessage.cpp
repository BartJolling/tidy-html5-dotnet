#include "FeedbackMessage.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace TidyHtml5Dotnet
{
	FeedbackMessage::FeedbackMessage(TidyMessage tmessage)
	{
		if (tmessage == nullptr)
			throw gcnew ArgumentNullException("tmessage", "Cannot create Message from null TidyMessage");

		_tmessage = tmessage;
		_key = gcnew String(tidyGetMessageKey(tmessage));
		_output = gcnew String(tidyGetMessageOutput(tmessage));

		TidyIterator pos;
		TidyMessageArgument arg;
		TidyFormatParameterType messageType;
		ctmbstr messageFormat;

		// loop through the arguments, if any, and fetch their details
		pos = tidyGetMessageArguments(tmessage);
		while (pos)
		{
			if (_arguments == nullptr)
				_arguments = gcnew List<String ^>();
				
			String ^ argument = String::Empty;
			arg = tidyGetNextMessageArgument(tmessage, &pos);
			messageType = tidyGetArgType(tmessage, &arg);

			switch (messageType)
			{
			case tidyFormatType_STRING:
				argument = gcnew String(tidyGetArgValueString(tmessage, &arg));
				break;

			case tidyFormatType_INT:
				argument = Convert::ToString(tidyGetArgValueInt(tmessage, &arg));
				break;

			case tidyFormatType_UINT:
				argument = Convert::ToString(tidyGetArgValueUInt(tmessage, &arg));
				break;

			case tidyFormatType_DOUBLE:
				argument = Convert::ToString(tidyGetArgValueDouble(tmessage, &arg));
				break;

			default:
				argument = String::Format("Unknown Message Type: {0}", (int)messageType);
			}

			_arguments->Add(argument);
		}
	};

	String ^ FeedbackMessage::ToString()
	{
		return String::Format("{0}, {1}", _key, _output);
	};

	String ^ FeedbackMessage::Key::get()
	{
		return _key;
	};

	String ^ FeedbackMessage::Output::get()
	{
		return _output;
	};

	IEnumerable<String ^> ^ FeedbackMessage::Arguments::get()
	{
		if (_arguments == nullptr)
			return Enumerable::Empty<String ^>();

		return _arguments;
	};
}