#include <cassert>
#include "Options.hpp"

namespace TidyHtml5Dotnet
{

	Options::Options(const TidyDoc tidyDoc)
	{
		assert(tidyDoc);
		_tidyDoc = tidyDoc;
	};
}