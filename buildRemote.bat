@echo off
mkdir C:\GitHob\SpaceInvaders\build
g++ C:\GitHob\SpaceInvaders\src\*.cpp -o C:\GitHob\SpaceInvaders\build\spaceinvaders.exe -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
pause
start C:\GitHob\SpaceInvaders\build\spaceinvaders.exe
