@echo off
cls


:: Vendo se é um debug ou uma release ::
set mode=%1
if "%mode%"=="" set mode=debug


:: Definindo qual compilador usar pra compilar ::
set compiler=clang

echo Compilador utilizado: %compiler%
echo WetLib - Iniciando compilacao


:: Arquivos a compilar, includes e flags ::
set files=^
        src/thirdparty/glad/src/glad.c^
        src/core/log.c^
        src/core/window.c^
        src/platforms/os/windows.c^
        src/core/graphics.c^
        src/platforms/gfx/opengl.c^
        src/core/time.c


set includes=-Iincludes -I./src/thirdparty/glad/include
set flags=


if "%mode%"=="release" (
    set flags=-O3 -DWET_RELEASE
) else if "%mode%"=="debug" (
    set flags=-g -DWET_DEBUG
) else (
    echo NÃO INDENTIFICADO SE É UM DEBUG OU RELEASE DA WETLIB
    set flags=-g -DWET_DEBUG
)


:: Executando o comando ::
echo Compilado Arquivos...
%compiler% -c %files% %includes% %flags%

if not exist output mkdir output

ar rcs libwet.a *.o

move *.a output >nul
del *.o

echo WetLib - compilacao concluida com sucesso!
