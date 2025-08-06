#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void concatena(char *destino, int quantidade, ...) {
    va_list args;
    va_start(args, quantidade);

    //destino[0] = '\0';  // Garante que a string esteja vazia no início

    for (int i = 0; i < quantidade; i++) {
        const char *str = va_arg(args, const char*);
        strcat(destino, str);  // Concatena a string no buffer destino
    }

    va_end(args);
}

int main() {
    char resultado[100];

    concatena(resultado, 3, "Olá, ", "mundo", "!");

    printf("Resultado: %s\n", resultado);  // Saída: Olá, mundo!

    return 0;
}