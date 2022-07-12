main: main.o libtest.a libother.a
	gcc -o ./build/main -Wl,--undefined=Foo -L./build -lother -ltest ./build/main.o
	#gcc -o ./build/main -L./build -Wl,--start-group -ltest -lother ./build/main.o -Wl,--end-group
	#gcc -o ./build/main ./build/main.o -L./build -ltest -lother
	#gcc -o ./build/main ./build/main.o -L./build -lother -ltest

main.o: main.c
	gcc -c ./main.c -o ./build/main.o

libtest.a: test1.o test2.o
	ar -crv ./build/libtest.a ./build/test1.o ./build/test2.o
test1.o: ./test/test1.c
	gcc -c ./test/test1.c -o ./build/test1.o
test2.o: ./test/test2.c
	gcc -c ./test/test2.c -o ./build/test2.o


libother.a: other_test1.o other_test2.o
	ar -crv ./build/libother.a ./build/other_test1.o ./build/other_test2.o
other_test1.o: ./other/other_test1.c
	gcc -c ./other/other_test1.c -o ./build/other_test1.o
other_test2.o: ./other/other_test2.o
	gcc -c ./other/other_test2.c -o ./build/other_test2.o

clean:
	rm -rf ./build/*
