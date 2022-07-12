all: main libtest.so

main: main.o libtest.a
	gcc main.o libtest.a -o main -lstdc++ -ldl

main.o: main.cpp test.h
	gcc main.cpp -I. -c -o main.o

libtest.a: test.o
	ar -crv ./libtest.a ./test.o

test.o: test.h test.c
	gcc test.c -fPIC -I. -c -o test.o

libtest.so: test.o
	gcc -shared test.o -o libtest.so

clean:
	rm -rf *.o *.a *.so main
