#include <cassert>
#include "Diagnostics.hpp"

namespace TidyHtml5Dotnet
{

	TidyHtml5Dotnet::Diagnostics::Diagnostics(const TidyDoc tidyDoc)
	{
		assert(tidyDoc);
		_tidyDoc = tidyDoc;
	};
}