@echo off

:: checking if devenv exits
:: where devenv >nul 2>&1
:: if %ERRORLEVEL% neq 0 (
::     echo Error: Visual Studio (devenv.exe) is not found in the system PATH.
::     echo Please make sure Visual Studio is installed and devenv.exe is available in the PATH.
::     pause
::     exit /b 1
:: )

set SOLUTION_NAME=LeetCodeSolutions.sln
set BUILD_DIR=build
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
set PROJECT_DIR=%~dp0
cd /d "%PROJECT_DIR%"
cd "%BUILD_DIR%"

:: generating solution
cmake -G "Visual Studio 17 2022" -A x64 ..

cd "%PROJECT_DIR%"

:: checking solution
if not exist "%BUILD_DIR%\%SOLUTION_NAME%" (
    echo Error: The generated solution file %SOLUTION_NAME% was not found.
    echo Please check the CMake output for errors.
    pause
    exit /b 1
) else (
    echo Solution has been generated in the build folder.
)

:: opening solution
tasklist /FI "IMAGENAME eq devenv.exe" 2>NUL | find /I /N "devenv.exe">NUL
if "%ERRORLEVEL%"=="0" (
    powershell -Command ^
    "if (-not (Get-Process devenv -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowTitle -match 'LeetCodeSolutions' })) { start devenv '%BUILD_DIR%\%SOLUTION_NAME%' }"
    echo Solution has been already opened in Visual Studio.
) else (
    echo Solution will be now opened in Visual Studio.
    start devenv "%BUILD_DIR%\%SOLUTION_NAME%"
)

pause