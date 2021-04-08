static:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building.)
	g++ -g expat-example-cpp.cpp -s -o expat-example-cpp-static.exe -Wl,-Bstatic -lexpat -lm
shared:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building, The DLL will be required for running.)
	g++ -g expat-example-cpp.cpp -s -o expat-example-cpp-shared.exe -Wl,-Bdynamic -lexpat -lm
static-msvc-clang-cl:
	$(info Once you run the make/mingw32-make/nmake command, make sure you have Expat library installed by using vcpkg install expat:x64-windows-static and the vcpkg path located at C:\src\vcpkg,)
	$(info LLVM Clang-cl and MSVC Libraries, otherwise the errors will throw on building.)
	clang-cl /EHs /MT -I"C:\src\vcpkg\installed\x64-windows-static\include" -c expat-example-cpp.cpp -o eee.o
	lld-link /OPT:NOICF /OUT:expat-example-cpp-static-clang.exe eec.o /LIBPATH:C:\src\vcpkg\installed\x64-windows-static\lib libexpatmd.lib
sftcp1:
        start youtube.com/sftcp1official
