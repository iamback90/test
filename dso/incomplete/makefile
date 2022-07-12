all: libtest.so main makefile
main: main.o libforeign.so
	gcc main.o -o main -L. -ltest -lstdc++ -ldl -Wl,-rpath,\$$ORIGIN -Wl,-E
	#gcc main.o -o main -L. -lforeign -ltest -lstdc++ -ldl -Wl,-rpath,\$$ORIGIN
main.o: main.cpp
	gcc main.cpp -c -o main.o
libtest.so: test.o
	gcc -shared test.o -o libtest.so
test.o: test.h test.c
	gcc -fPIC test.c -c -o test.o
libforeign.so: foreign.o
	gcc -shared foreign.o -o libforeign.so
foreign.o: foreign.h foreign.c
	gcc -fPIC foreign.c -c -o foreign.o
clean:
	rm *.o *.so main
