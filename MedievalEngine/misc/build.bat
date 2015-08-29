@echo off

REM MedievalEngine 2015
REM Pedro Henrique system.pedorhenrique@gmail.com
REM Visual Studio 2015 Build

REM cl Compiler
REM /nologo Remove a mensagem do compilador
REM /Wall Habilita todos dos avisos
REM /Zi Faz um executavel com informações de debug
REM /W3 Level 3 de Warning
REM /WX Trata Warning como erros
REM /Fo Define o diretorio para os arquivos obj
REM /EHsc Exception handling
REM /MTd (/MT para release) Faz a aplicação usar multithread, static version of the run-time library
REM /MDd Faz a aplicação usar multithread, dll's (tem que instalar Dll's MSVCRTversion.dll)
REM /Fe Define o nome do arquivo de saida
REM /FC Mostra o path completo dos executaveis
REM /I Include's
REM /link Para utilizar opções do Linker
REM /LIBPATH:PATH Define um path para os lib's

REM setlocal Define uma opção de como deve ser a visibilidade das
REM variáveis no arquivo batch
REM enabledelayedexpansion Define que as variáveis devem ser expandidas
REM durante o tempo de execução e não de parse

setlocal enabledelayedexpansion
SET outexe=MedievalEngine.exe
SET flags=/W3 /Fo.\obj\ /Zi /MDd /EHsc /nologo /FC /Fe%outexe%
SET defines=/D__WIN32=1 /D_CRT_SECURE_NO_WARNINGS=1
SET includes=/I"C:\MedievalEngine\MedievalEngine\Engine" /I"C:\Program Files (x86)\SFML\include" /I"C:\Program Files (x86)\lua\include" /I"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include"
SET libs="sfml-graphics-d.lib" "sfml-window-d.lib" "sfml-audio-d.lib" "sfml-system-d.lib" /link /LIBPATH:"C:\SFML\lib"
SET sources=

REM Consegue a lista de arquivos para ser compilado
pushd .\MedievalEngine\Engine\
FOR /R %%i IN (*.cpp) DO set sources=!sources! %%i
popd

IF NOT EXIST .\build mkdir .\build
pushd .\build
IF NOT EXIST .\obj mkdir .\obj
cl %defines% %flags% %includes% %sources% %libs%
popd
