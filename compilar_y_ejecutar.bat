@echo off
cd /d "%~dp0"
echo Compilando el proyecto con CMake...
C:\msys64\ucrt64\bin\cmake.exe --build build
if %errorlevel% neq 0 (
    echo.
    echo Hubo un error al compilar.
    pause
    exit /b %errorlevel%
)
echo.
echo Ejecutando ProyectoOpenGL...
.\build\ProyectoOpenGL.exe
