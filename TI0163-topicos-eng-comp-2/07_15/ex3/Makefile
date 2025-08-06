CC = gcc
CFLAGS = -Wall -g
TARGET = app
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
#@echo "TARGET $@ $^"
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
#@echo "OBJ %.c %.o $< $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)


print-vars:
	@echo "OBJS = $(SRCS:.c=.o)"
