@echo off
cls


gcc main.c ../output/libwet.a -I../includes -o test.exe -lopengl32 -lgdi32 -DWET_DEBUG
