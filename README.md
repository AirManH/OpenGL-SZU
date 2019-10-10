# OpenGL-SZU

## Build

### Linux

install *freeglut* and *glew*

``` bash
cd Path/To/OpenGL-SZU/exp{exp_number}/
```

`sh ./build.sh` to build

`sh ./clean.sh` to clean the build

### Windows with Mingw-w64

Install  [*Mingw-w64*](http://mingw-w64.org/) and [*CMake*](https://cmake.org/)

**Optional**: install *freeglut* and *glew* yourself. Here we provide *freeglut 2.1.0* from [there](http://glew.sourceforge.net/) and *freeglut 3.0.0 MinGW Package* from [there](https://www.transmissionzero.co.uk/software/freeglut-devel/).

In *PowerShell*:

``` PowerShell
cd Path\To\OpenGL-SZU\exp{exp_number}\
```

`.\build.ps1` to build

`.\clean.ps1` to clean the build
