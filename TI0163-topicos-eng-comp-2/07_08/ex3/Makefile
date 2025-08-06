
CC = gcc
CFLAGS = -Iinclude -Iunity -Wall -Wextra
SRC = array_utils.c
UNITY_SRC = unity/unity.c
TESTS = test_array_utils.c
OUT = test_array_run.o

all: test

test:
	$(CC) $(CFLAGS) $(SRC) $(UNITY_SRC) $(TESTS) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
