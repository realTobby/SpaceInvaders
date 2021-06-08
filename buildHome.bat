@echo off
mkdir D:\Programmierung\SpaceInvaders\build
g++ D:\Programmierung\SpaceInvaders\src\*.cpp -o D:\Programmierung\SpaceInvaders\build\spaceinvaders.exe -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
pause
start D:\Programmierung\SpaceInvaders\build\spaceinvaders.exe
