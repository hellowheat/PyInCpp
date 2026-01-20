@echo off
echo ========================================
echo PyInCpp Test Runner
echo ========================================
echo.

if not exist build (
    echo Creating build directory...
    mkdir build
)

cd build

echo.
echo Configuring CMake...
cmake .. || goto error

echo.
echo Building project...
cmake --build . || goto error

echo.
echo Running tests...
.\Debug\test_pyincpp.exe

goto end

:error
echo.
echo ========================================
echo Error occurred during testing!
echo ========================================
exit /b 1

:end
cd ..
