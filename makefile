CC = gcc
CFLAGS = -I.
DEPS = find_intersection.h
OBJ = main.o find_intersection.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

find_intersection: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
