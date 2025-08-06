# Diretórios
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Lista todos os arquivos .c dentro de src/ e subpastas
SRC := $(shell find $(SRC_DIR) -name "*.c")

# Gera lista de objetos correspondente na pasta build/
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Alvo final
TARGET := app

# Flags do compilador
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -O2

# Regra padrão
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Linka todos os objetos
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Limpar/clean
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
