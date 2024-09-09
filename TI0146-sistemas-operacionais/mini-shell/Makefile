CC = gcc
FLAGS = -Wall -Wextra -Wfloat-equal -Wshadow -Wpointer-arith -Wcast-align -Wconversion
TARGET:=$(shell cd ./target && pwd)

OBJ_FILES=$(TARGET)/command.o $(TARGET)/main.o $(TARGET)/redirection.o $(TARGET)/token.o

all: minishell
build: $(OBJ_FILES)

clear: 
	rm -rf target/*

run: all
	./minishell

$(OBJ_FILES):
	make all -C ./src TARGET=$(TARGET) CC=$(CC) FLAGS=$(FLAGS)

minishell: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o minishell 
