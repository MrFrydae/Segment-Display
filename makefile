SOURCE = $(wildcard *.c)
OBJS = $(SOURCE:.c=.o)
HEADER = $(wildcard *.h)
OUT = display
CC = gcc
FLAGS = -g -Wall
LFLAGS = -lm

all: $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(OUT) $(LFLAGS)

clean:
		rm -f $(OBJS) $(OUT)