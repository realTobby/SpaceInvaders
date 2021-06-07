@echo off
:start
g++ D:\Programmierung\SpaceInvaders\src\*.cpp -o D:\Programmierung\SpaceInvaders\build\spaceinvaders.exe -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
pause
goto start
