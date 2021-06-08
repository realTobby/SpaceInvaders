@echo off
mkdir builds
g++ src\*.cpp -o builds\spaceinvaders.exe -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
pause
start builds\spaceinvaders.exe
