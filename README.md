# OpenGL-SZU

Build solution for the course *Interactive Computer Graphics* in SZU.

为深圳大学**计算机图形学**的实验代码提供构建方案。

## Build 构建

### Linux

install *freeglut* and *glew*

``` bash
cd Path/To/OpenGL-SZU/src/
```

`sh ./build.sh` to build

`sh ./clean.sh` to clean the build

### Windows with Mingw-w64

Install  [*Mingw-w64*](http://mingw-w64.org/) and [*CMake*](https://cmake.org/)

**Optional**: install *freeglut* and *glew* yourself. Here we provide *glew 2.1.0* from [there](http://glew.sourceforge.net/) and *freeglut 3.0.0 MinGW Package* from [there](https://www.transmissionzero.co.uk/software/freeglut-devel/). 这里我们已经提供了 [*glew 2.1.0*](http://glew.sourceforge.net/) 和 [*freeglut 3.0.0 MinGW Package*](https://www.transmissionzero.co.uk/software/freeglut-devel/) 。你也可以自己下载安装 freeglut 和 glew ，请确保 CMake 可以找到他们。

In *PowerShell*:

``` PowerShell
cd Path\To\OpenGL-SZU\src\
```

`.\build.ps1` to build

`.\clean.ps1` to clean the build

## Known problems 已知的问题

- 使用Intel集显运行程序，Windows 10, 打开窗口时为白屏
  暂时的解决办法：拉伸窗口使其刷新窗口

- 使用Intel集显运行程序，Ubuntu 16.04，程序无法运行，控制台中提示
 `vshader.glsl failed to compile:
0:1(10): error: GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.00 ES, 3.00 ES, 3.10 ES, and 3.20 ES`
 暂时的解决办法：`export MESA_GL_VERSION_OVERRIDE=3.3`
