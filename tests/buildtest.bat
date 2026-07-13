@echo off
cls


gcc main.c ../output/libwet.a -O3 -I../includes -o test.exe -lopengl32 -lgdi32 -lwinmm -DWET_DEBUG
