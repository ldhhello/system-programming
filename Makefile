.PHONY: all clean

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c, %, $(SRCS))
CFLAGS = -Wall -pthread

all: $(PROGS)
