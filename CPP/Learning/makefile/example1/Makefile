#target : dependency files created by other targets

# Target are either an EXECUTABLE (e.g main.o) or an ACTION (clean)
#		what to do with the dependencies

#Targets will not be compiled if dependencies are not changed

CC=g++
CFLAGS=-c -Wall -std=c11
all: hello

hello: main.o function1.o function2.o date.o
	$(CC) main.o function1.o function2.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

function1.o: function1.cpp
	$(CC) $(CFLAGS) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAGS) function2.cpp

date.o: date.cpp
	$(CC) $(CFLAGS) date.cpp
clean:
	rm -rf *o hello
