@echo off

REM MedievalEngine 2015
REM Pedro Henrique system.pedorhenrique@gmail.com
REM Visual Studio 2015 Build fast but without debug information


setlocal enabledelayedexpansion
SET outexe=MedievalEngine.exe
SET flags=/Fe%outexe% /W3 /Fo.\obj\ /MDd /EHsc /nologo /FC /fp:precise
SET defines=/D__WIN32 /D_CRT_SECURE_NO_WARNINGS
SET libs="sfml-graphics-d.lib" "sfml-window-d.lib" "sfml-audio-d.lib" "sfml-system-d.lib"  "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /link /MACHINE:X64 /INCREMENTAL  /LIBPATH:"C:\SFML\lib" /TLBID:1
SET includes=/I"C:\MedievalEngine\MedievalEngine\Engine" /I"C:\Program Files (x86)\SFML\include" /I"C:\Program Files (x86)\lua\include" /I"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include"
SET sources=

REM Consegue a lista de arquivos para ser compilado
pushd .\MedievalEngine\Engine\
FOR /R %%i IN (*.cpp) DO set sources=!sources! %%i
popd

IF NOT EXIST .\build mkdir .\build
pushd .\build
IF EXIST %outexe% DEL %outexe%
IF NOT EXIST .\obj mkdir .\obj
cl %flags% %defines% %includes% %sources% %libs%
popd
