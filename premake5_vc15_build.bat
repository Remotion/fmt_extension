@echo off

CD /D %~dp0

echo #############################################################################################
echo Starting %~n0 %date% %time%
echo #############################################################################################

set PROJECT_NAME=fmt_extension
set EXE_NAME=bin/x64/debug/fmt_extension

::md build_vs2017
::cd build_vs2017
premake5 vs2017
if %ERRORLEVEL% NEQ 0 (
  echo "Error: " %ERRORLEVEL%
  pause
  exit 
)


@call "%VS2017INSTALLDIR%\VC\Auxiliary\Build\vcvars64.bat"

cd vs2017
msbuild "%PROJECT_NAME%.sln" /p:Configuration=debug /p:Platform=x64 /maxcpucount /nologo /verbosity:m
if %ERRORLEVEL% NEQ 0 (
  echo "Error: " %ERRORLEVEL%
  pause
  exit
)

echo #############################################################################################
echo Starting "%EXE_NAME%.exe" %date% %time%
echo #############################################################################################
echo.
call "%EXE_NAME%.exe"
echo.
echo _____________________________________________________________________________________________
pause 
