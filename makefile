CC = gcc
CFLAGS = -I.
DEPS = find_intersection.h tests.h
OBJ = main.o find_intersection.o tests.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

find_intersection: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
