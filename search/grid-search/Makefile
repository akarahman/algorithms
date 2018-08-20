# compiler to be used
CC=g++

# flags to pass to compiler
CFLAGS=-g -Wall -std=c++11

# flags to pass to compiler
FILES=driver.cpp solution.cpp

all: program

program: $(FILES) solution.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program