# compiler to be used
CC=gcc

# flags to pass to compiler
CFLAGS=-g -Wall

# flags to pass to compiler
FILES=driver.c paint_fill.c

all: program

program: $(FILES) paint_fill.h
	$(CC) $(CFLAGS) $(FILES) -o $@

.PHONY: clean

clean:
	rm program