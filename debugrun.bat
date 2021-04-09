@echo off
::build
mkdir build
cd build
cmake ..
cmake --build .
cd ..
::cd build/Debug
cd bin
::START /build/Debug/app.exe
START /wait SDL2Test.exe
@echo \
pause