all: main
main: main.o
	gcc main.o -o main -lstdc++
main.o: main.cpp
	gcc main.cpp -c -o main.o
clean:
	rm -rf main *.o
