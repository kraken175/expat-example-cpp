# expat-example-cpp
This is the Expat XML Example Code repository for C++ from this video:
https://www.youtube.com/watch?v=SLucn4QjdBU

Including more flavors and so on from Kraken175.

MinGW Building Requirements:

1. GNU Make
2. MinGW Compiler
3. Expat Library (if you installed)
4. Expat DLL to run shared executable

MSVC Building Requirements:
1. CMake
2. vcpkg
3. Expat library

GNU Make Parameters (by default: static):

1. static - Make a static executable file
2. shared - Make a shared executable file

To compile with MSVC:
cmake "-DCMAKE_TOOLCHAIN_FILE=C:\src\vcpkg\scripts\buildsystems\vcpkg.cmake" ..
cmake --build ..

To setup vcpkg, Please read vcpkg_setup.md
