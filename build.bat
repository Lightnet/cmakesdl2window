@echo off
mkdir build
cd build
cmake ..
cmake --build .
::cmake .. -DCMAKE_INSTALL_PREFIX=../_install
pause