using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute(L"tidy-html5-dotnet")];
[assembly:AssemblyDescriptionAttribute(L".NET wrapper around tidy-html5 for Windows")];
#if NDEBUG
[assembly:AssemblyConfigurationAttribute(L"Release")];
#else
[assembly:AssemblyConfigurationAttribute(L"Debug")];
#endif
[assembly:AssemblyCompanyAttribute(L"Thosa IT NV")];
[assembly:AssemblyProductAttribute(L"tidy-html5-dotnet")];
[assembly:AssemblyCopyrightAttribute(L"Copyright (c) Thosa IT NV 2024")];
[assembly:AssemblyTrademarkAttribute(L"")];
[assembly:AssemblyCultureAttribute(L"")];

[assembly:AssemblyVersionAttribute(L"5.8.0.*")];

[assembly:ComVisible(false)];
