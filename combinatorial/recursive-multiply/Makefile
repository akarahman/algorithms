# compiler to be used
CC=gcc

# flags to pass to compiler
CFLAGS=-g -Wall

# flags to pass to compiler
FILES=driver.c

all: program

program: $(FILES) solution.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program