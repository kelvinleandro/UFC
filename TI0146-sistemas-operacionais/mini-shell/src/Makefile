MAIN_OBJ=$(TARGET)/main.o
COMMAND_OBJ=$(TARGET)/command.o $(TARGET)/redirection.o
TOKEN_OBJ=$(TARGET)/token.o

all: $(COMMAND_OBJ) $(MAIN_OBJ) $(TOKEN_OBJ)

$(MAIN_OBJ): ./main.c
	$(CC) -c ./main.c  -o $(TARGET)/main.o $(FLAGS)

$(COMMAND_OBJ): ./command
	@echo "TARGET=$(TARGET) CC=$(CC) FLAGS=$(FLAGS)"
	make all -C ./command TARGET=$(TARGET) CC=$(CC) FLAGS=$(FLAGS)

$(TOKEN_OBJ): ./token.c
	$(CC) -c ./token.c  -o $(TARGET)/token.o $(FLAGS)
	

