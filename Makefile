CC = g++

CFLAGS = -c -Wall

all: run

run:
	$(CC) main.cpp mock/mocker.cpp test/tester.cpp -o run

.PHONY : clean
clean:
	rm -rf *.o run
