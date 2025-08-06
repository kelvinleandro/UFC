CC = gcc
CFLAGS = -Wall -g
TARGET = hello
SRC = hello.c

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

print_vars:
	@echo "CC  = $(CC)"
	@echo "CFLAGS = $(CFLAGS)"
