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
			messageFormat = tidyGetArgFormat(tmessage, &arg);

			switch (messageType)
			{
			case tidyFormatType_STRING:
				argument = String::Format(ARGUMENT_FORMAT, (int)messageType, gcnew String(messageFormat), gcnew String(tidyGetArgValueString(tmessage, &arg)));
				break;

			case tidyFormatType_INT:
				argument = String::Format(ARGUMENT_FORMAT, (int)messageType, gcnew String(messageFormat), tidyGetArgValueInt(tmessage, &arg));
				break;

			case tidyFormatType_UINT:
				argument = String::Format(ARGUMENT_FORMAT, (int)messageType, gcnew String(messageFormat), tidyGetArgValueUInt(tmessage, &arg));
				break;

			case tidyFormatType_DOUBLE:
				argument = String::Format(ARGUMENT_FORMAT, (int)messageType, gcnew String(messageFormat), tidyGetArgValueDouble(tmessage, &arg));
				break;

			default:
				argument = String::Format(ARGUMENT_FORMAT, (int)messageType, gcnew String(messageFormat), gcnew String("unknown so far"));
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