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

Install [*Mingw-w64*](http://mingw-w64.org/) and [*CMake*](https://cmake.org/). Set **PATH**.

<details><summary>如何安装Mingw-w64</summary>

<p>

两个推荐方案

1. 在线安装：进入[*sourceforge.net*](https://sourceforge.net/projects/mingw-w64/files/)，找到*MinGW-W64 Online Installer MinGW-W64-install.exe*，点击下载
2. 离线安装：进入[*sourceforge.net*](https://sourceforge.net/projects/mingw-w64/files/)，依次点击（下载量较多的）*Toolchains targetting Win64*，*Personal Builds*，*mingw-builds*，*{最新版本}*，*threads-posix*，*seh*，下载对应的压缩包。

</p>
</details>

**Optional**: Install *freeglut* and *glew* yourself. Here we provide *glew 2.1.0* from [there](http://glew.sourceforge.net/) and *freeglut 3.0.0 MinGW Package* from [there](https://www.transmissionzero.co.uk/software/freeglut-devel/). 这里我们已经提供了 [*glew 2.1.0*](http://glew.sourceforge.net/) 和 [*freeglut 3.0.0 MinGW Package*](https://www.transmissionzero.co.uk/software/freeglut-devel/) 你也可以自己下载安装 freeglut 和 glew ，请确保 CMake 可以找到他们。

In *PowerShell* or *cmd*:

``` cmd
cd Path/To/OpenGL-SZU/src/
```

`./build.bat` to build

`./clean.bat` to clean the build

## Usage 使用方法

Successful build result is `/src/build/main` 每次成功构建后，生成的可执行文件为`/src/build/main`

### Add header files 添加头文件

you can put your header files (like .h) in [/src/include](src/include/). 你可以把头文件（形如.h）添加到[/src/include](src/include/)中。

Or in [CMakeLists.txt](src/CMakeLists.txt), there are lines:

``` cmake
# include

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/glew-2.1.0/include/)
    include_directories(${CMAKE_SOURCE_DIR}/freeglut-3.0.0-MinGW/include/)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)
```

use [`include_directories()`](https://cmake.org/cmake/help/v3.0/command/include_directories.html) to add your headfile files.

### Add source files 添加源文件

In [CMakeLists.txt](src/CMakeLists.txt), there are lines:

``` cmake
add_executable(main main.cpp ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp)
```

append your source files separated by spaces `" "`

For example, if you have `src/a.cpp` to compile, above could be 

``` cmake
add_executable(main main.cpp a.cpp ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp)
```

or

``` cmake
add_executable(main main.cpp ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp ${CMAKE_SOURCE_DIR}/a.cpp)
```

For more information, see [add_executable](https://cmake.org/cmake/help/v3.0/command/add_executable.html)

## Known problems 已知的问题

- 使用Intel集显运行程序，Windows 10, 打开窗口时为白屏

  暂时的解决办法：拉伸窗口使其刷新窗口

- 使用Intel集显运行程序，Ubuntu 16.04，程序无法运行，控制台中提示

  ``` bash
  vshader.glsl failed to compile:
  0:1(10): error: GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.00 ES, 3.00 ES, 3.10 ES, and 3.20 ES
  ```

  暂时的解决办法：`export MESA_GL_VERSION_OVERRIDE=3.3`
