clang-cl -I"C:\src\vcpkg\installed\x64-windows-static\include" /Os -c expat_xml.cc /Foexpat_xml.obj
lld-link /OUT:expat_xml-clang.exe expat_xml.obj /LIBPATH:"C:\src\vcpkg\installed\x64-windows-static\lib" libexpatmd.lib
