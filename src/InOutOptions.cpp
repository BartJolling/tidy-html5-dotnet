#include <cassert>
#include "InOutOptions.hpp"

namespace TidyHtml5Dotnet
{
	TidyHtml5Dotnet::InOutOptions::InOutOptions(const TidyDoc tidyDoc)
	{
		assert(tidyDoc);
		_tidyDoc = tidyDoc;
	};
}