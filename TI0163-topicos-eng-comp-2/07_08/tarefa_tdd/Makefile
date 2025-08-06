
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Iunity
SRC = deti.c
TEST_SRC = test_deti.c unity/unity.c
OUT = test_deti_run.o

all: test

test:
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
