msbuild.exe %~dp0..\..\tidy-html5-dotnet.sln -t:build -restore -p:RestorePackagesConfig=true /p:IncludePath="..\include;$(IncludePath)" -p:Configuration=Release -p:Platform=x64 -fl -flp:logfile=MyProjectOutput.log;verbosity=diagnostic
if errorlevel 1 goto error

copy %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\tidy-html5-dotnet.tests.runtimeconfig.json %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\testhost.runtimeconfig.json
vstest.console.exe %~dp0..\..\tidy-html5-dotnet.tests\bin\x64\Release\net8.0-windows\tidy-html5-dotnet.tests.dll
goto done

error:
echo Build Failed! Tests skipped.

done:
echo Done