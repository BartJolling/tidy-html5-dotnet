#include <cassert>
#include "FileOptions.hpp"

namespace TidyHtml5Dotnet
{
	TidyHtml5Dotnet::FileOptions::FileOptions(const TidyDoc tidyDoc)
	{
		assert(tidyDoc);
		_tidyDoc = tidyDoc;
	};
}
