
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Iunity
SRC = calc.c
TEST_SRC = test_calc.c unity/unity.c
OUT = test_calc_run.o

all: test

test:
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
