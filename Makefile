static:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building.)
	g++ -g expat-example-cpp.cpp -s -o out/static/expat-example-cpp.exe -Wl,-Bstatic -lexpat -lm
shared:
	$(info Once you run the make/mingw32-make command, make sure you have Expat library installed and the MinGW compiler. or else the errors will throw on building.)
	g++ -g expat-example-cpp.cpp -s -o out/shared/expat-example-cpp.exe -Wl,-Bdynamic -lexpat -lm