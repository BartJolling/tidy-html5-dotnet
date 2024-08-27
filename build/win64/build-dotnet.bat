@echo off
msbuild.exe %~dp0..\..\tidy-html5-dotnet.sln -t:build -restore -p:RestorePackagesConfig=true /p:IncludePath="..\include;$(IncludePath)" -p:Configuration=Release -p:Platform=x64
if errorlevel 1 goto builderror

copy %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\tidy-html5-dotnet.tests.runtimeconfig.json %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\testhost.runtimeconfig.json
vstest.console.exe %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\tidy-html5-dotnet.tests.dll
if errorlevel 1 goto testerror

goto :eof

: builderror
echo Build Failed! Tests skipped.
goto :eof

: testerror
echo Build Succeeded. Test Run failed!
goto :eof
