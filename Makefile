CC = gcc
CFLAGS = -std=c11 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = linkedlist

SRC_DIR = .
TEST_DIR = linked_lists
SRCS = main.c helper.c
OBJS = $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

test1: $(EXEC)
	./$(EXEC) $(TEST_DIR)/trace1.txt

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(TEST_DIR)/trace7.txt

clean: 
	rm -f linkedlist *.o output?? *~