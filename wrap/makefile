main: main.o libtest.so
	gcc main.o -o main -L. -ltest -Wl,--wrap=Test,-rpath=\$$ORIGIN/

main.o: main.c
	gcc main.c -c -o main.o

libtest.so: test.o
	gcc test.o -shared -o libtest.so

test.o: test.c
	gcc test.c -fPIC -c -o test.o

clean:
	rm -rf *.o *.so main
