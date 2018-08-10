# compiler to be used
CC=g++

# flags to pass to compiler
CFLAGS=-g -Wall -std=c++11

# flags to pass to compiler
FILES=driver.cpp

all: insort

insort: $(FILES) insertion_sort.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm test