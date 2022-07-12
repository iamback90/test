unwind_bt: unwind_bt.o
	gcc unwind_bt.o -o unwind_bt -lunwind

unwind_bt.o: unwind_bt.c
	gcc unwind_bt.c -c -o unwind_bt.o

clean:
	rm -rf unwind_bt *.o
