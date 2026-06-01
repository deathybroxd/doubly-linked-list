CXX = g++
CXXFLAGS = -Wall -g

DLL:
	$(CXX) $(CXXFLAGS) DLL_test.cpp DLL.h -o DLL_test

DLL.o: DLL.h
	$(CXX) $(CXXFLAGS) -c DLL.h

run:
	./DLL_test

val:
	valgrind ./DLL_test