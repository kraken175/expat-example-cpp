VCPKG Setup:

1. cd C:\
2. mkdir src
3. cd src
4. git clone https://github.com/microsoft/vcpkg.git
5. cd vcpkg
6. bootstrap-vcpkg.bat

And to install expat:
    For static library - vcpkg install expat:x64-windows-static
    For shared library - vcpkg install expat:x64-windows
