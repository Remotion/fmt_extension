@echo off

CD /D %~dp0

echo #############################################################################################
echo Starting %~n0 %date% %time%
echo #############################################################################################

set PROJECT_NAME=fmt_extension
set EXE_NAME=fmt_extension

md build_ninja
cd build_ninja
cmake .. -G"Ninja"
if %ERRORLEVEL% NEQ 0 (
  echo "Error: " %ERRORLEVEL%
  pause
  exit 
)

ninja
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
