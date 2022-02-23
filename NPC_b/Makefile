CC=gcc
CFLAGS=-W -Wall -std=c99
TARGET=out
OBJS = npc_b.o

all: $(TARGET)

out: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o $(TARGET)
