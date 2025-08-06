CC = gcc
TARGET = main.o
SRCS = main.c soma.c sub.c mul.c div.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run