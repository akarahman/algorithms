# compiler to be used
CC=g++

# flags to pass to compiler
CFLAGS=-g -Wall -std=c++11

# flags to pass to compiler
FILES=driver.cpp coins.cpp

all: program

program: $(FILES) coins.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program