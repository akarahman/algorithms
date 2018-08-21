# compiler to be used
CC=g++

# flags to pass to compiler
CFLAGS=-g -Wall

# flags to pass to compiler
FILES=driver.cpp visual.cpp

all: program

program: $(FILES) solution.h visual.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program