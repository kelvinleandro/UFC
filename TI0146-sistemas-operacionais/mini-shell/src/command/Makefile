COMMAND_OBJ=$(TARGET)/command.o
REDIR_OBJ=$(TARGET)/redirection.o

all: $(COMMAND_OBJ) $(REDIR_OBJ)

$(COMMAND_OBJ): ./command.c
	$(CC) -c command.c -o $(TARGET)/command.o $(FLAGS)

$(REDIR_OBJ): ./redirection.c
	$(CC) -c redirection.c -o $(TARGET)/redirection.o $(FLAGS)
