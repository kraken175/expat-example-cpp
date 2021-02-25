static:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building.)
	g++ -g expat-example-cpp.cpp -s -o expat-example-cpp-static.exe -Wl,-Bstatic -lexpat -lm
shared:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building, The DLL will be required for running.)
	g++ -g expat-example-cpp.cpp -s -o expat-example-cpp-shared.exe -Wl,-Bdynamic -lexpat -lm
sftcp1:
        start youtube.com/sftcp1official
