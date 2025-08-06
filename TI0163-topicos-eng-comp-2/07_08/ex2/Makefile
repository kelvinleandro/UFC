
CC = gcc
CFLAGS = -Iinclude -Iunity -Wall -Wextra
SRC = str_utils.c
UNITY_SRC = unity/unity.c
TESTS = test_str_utils.c
OUT = test_str_run.o

all: test

test:
	$(CC) $(CFLAGS) $(SRC) $(UNITY_SRC) $(TESTS) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
