#include <cassert>
#include "DisplayOptions.hpp"

namespace TidyHtml5Dotnet
{

	TidyHtml5Dotnet::DisplayOptions::DisplayOptions(const TidyDoc tidyDoc)
	{
		assert(tidyDoc);
		_tidyDoc = tidyDoc;
	};
}
