CXXFLAGS = --coverage -g -O0

main: main.o funcs.o caesar.o 
	g++ -o main main.o funcs.o caesar.o --coverage -g -O0

tests: tests.o funcs.o caesar.o
	g++ -o tests tests.o funcs.o caesar.o --coverage -g -O0
	gcovr 2> /dev/null > /dev/null
	gcovr --html-details coverage.html

caesar.o: caesar.cpp caesar.h funcs.h
	g++ -c caesar.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp caesar.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h caesar.h 
	g++ -c tests.cpp

clean:
	rm -f *.o 
