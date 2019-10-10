# exp1

## Build

### Ubuntu 16.04

install *freeglut* and *glew* 

``` bash
cd Path/To/OpenGL-SZU
mkdir build
cd build
cmake ../exp1
make
```

### Windows with Mingw-w64

Install *Mingw-w64* and set PATH

In PowerShell (Not Git Bash):

``` bash
cd Path/To/OpenGL-SZU
mkdir build
cd build
cmake -G "MinGW Makefiles" ..\exp1\
mingw32-make.exe
```