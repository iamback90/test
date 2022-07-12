#main: main.o test0.o test1.o
#	gcc main.o test0.o test1.o -o main

#main: main.o libtest.a
#	gcc main.o -L. -ltest -o main

#main: main.o libtest0.a libtest1.a
#	gcc main.o -L. -ltest1 -ltest0 -o main
#	gcc main.o -L. -ltest0 -ltest1 -o main

main: main.o libdsotest0.so libdsotest1.so
	gcc main.o -L. -ldsotest0 -ldsotest1 -o main -Wl,-rpath=\$$ORIGIN/

main.o: main.c
	gcc -c -g main.c -o main.o

libtest.a: test0.o test1.o
	ar -cvr libtest.a test0.o test1.o

libtest0.a: test0.o
	ar -cvr libtest0.a test0.o

libtest1.a: test1.o
	ar -cvr libtest1.a test1.o

libdsotest0.so: test0.o
	gcc -shared test0.o -o libdsotest0.so
libdsotest1.so: test1.o
	gcc -shared test1.o -o libdsotest1.so

test0.o: test0.c
	gcc -c -g -fPIC test0.c -o test0.o

test1.o: test1.c
	gcc -c -g -fPIC test1.c -o test1.o

clean:
	rm -rf *.o main *.a *.so
