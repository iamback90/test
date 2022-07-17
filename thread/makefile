CC = gcc
CFLAGS = -std=c++11
LDFLAGS = -lstdc++ -lpthread

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

