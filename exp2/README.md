# exp1

## Build

### Ubuntu 16.04

install *freeglut* and *glew*

``` bash
cd Path/To/OpenGL-SZU
mkdir build
cd build
cmake ../exp{exp_number}
make
```

### Windows with Mingw-w64

Install  [*Mingw-w64*](http://mingw-w64.org/) and [*CMake*](https://cmake.org/)

**Optinal**: install *freeglut* and *glew* yourself. Here we provide *freeglut 2.1.0* from [there](http://glew.sourceforge.net/) and *freeglut 3.0.0 MinGW Package* from [there](https://www.transmissionzero.co.uk/software/freeglut-devel/).

In *PowerShell* or *cmd* (Not *Git Bash*):

``` bash
cd Path/To/OpenGL-SZU
mkdir build
cd build
cmake -G "MinGW Makefiles" ..\exp{exp_number}\
mingw32-make.exe
```

or just `build.ps1` to build and `clean.ps1` to clean the build (in *PowerShell*).
