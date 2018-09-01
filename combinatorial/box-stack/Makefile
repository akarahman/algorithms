# compiler to be used
CC=g++

# flags to pass to compiler
CFLAGS=-g -Wall -std=c++11

# flags to pass to compiler
FILES=driver.cpp box_stack.cpp

all: program

program: $(FILES) box_stack.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program