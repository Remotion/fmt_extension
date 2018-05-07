@echo off

CD /D %~dp0

echo #############################################################################################
echo Starting %~n0 %date% %time%
echo #############################################################################################

set PROJECT_NAME=fmt_extension
set EXE_NAME=fmt_extension

md build_vs2017
cd build_vs2017
cmake .. -G"Visual Studio 15 2017 Win64" -DCMAKE_SUPPRESS_REGENERATION=true 
if %ERRORLEVEL% NEQ 0 (
  echo "Error: " %ERRORLEVEL%
  pause
  exit 
)

@call "%VS2017INSTALLDIR%\VC\Auxiliary\Build\vcvars64.bat"

msbuild "%PROJECT_NAME%.sln" /p:Configuration=debug /p:Platform=x64 /m 
if %ERRORLEVEL% NEQ 0 (
  echo "Error: " %ERRORLEVEL%
  pause
  exit
)

echo #############################################################################################
echo Starting "%EXE_NAME%.exe" %date% %time%
echo #############################################################################################
echo.
call "debug/%EXE_NAME%.exe"
echo.
echo _____________________________________________________________________________________________
pause 
