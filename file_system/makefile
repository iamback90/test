CC = gcc
CFLAGS = -std=c++17
LDFLAGS = -lstdc++ -lstdc++fs

EXE = main
OBJECTS = main.o

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $< -o $@ $(LDFLAGS)

$(OBJECTS): %.o: %.cpp
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -rf $(EXE) $(OBJECTS)
