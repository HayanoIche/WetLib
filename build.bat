@echo off
cls


:: Vendo se é um debug ou uma release ::
set mode=%1
if "%mode%"=="" set mode=debug


:: Definindo qual compilador usar pra compilar ::
set compiler=gcc

echo Compilador utilizado: %compiler%
echo WetLib - Iniciando compilacao


:: Arquivos a compilar, includes e flags ::
set files=^
        src/thirdparty/glad/src/glad.c^
        src/platforms/os/windows.c^
        src/core/log.c^
        src/core/time.c^
        src/core/graphics.c^
        src/platforms/renderer/openGl/opengl.c^
        src/platforms/renderer/openGl/opengl_shaders.c^
        src/platforms/renderer/openGl/opengl_surface.c^
        src/platforms/renderer/openGl/opengl_draw.c^
        src/platforms/renderer/openGl/opengl_quad.c



set includes=-I. -Iincludes -I./src/thirdparty/glad/include
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

ar rcs libwet.a glad.o windows.o log.o time.o graphics.o opengl.o opengl_shaders.o opengl_surface.o opengl_draw.o opengl_quad.o

move *.a output >nul
del *.o

echo WetLib - compilacao concluida com sucesso!

cd "tests"

call "buildtest.bat"
start /wait "" "test.exe"

