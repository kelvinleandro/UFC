#include <stdio.h>
#include <stdarg.h>

// Função que recebe um número variável de inteiros e retorna a soma
int soma_variavel(int quantidade, ...) {
    va_list args;             // Declara uma lista de argumentos
    va_start(args, quantidade); // Inicializa a lista a partir do último argumento fixo

    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        int valor = va_arg(args, int); // Lê o próximo argumento como int
        soma += valor;
    }

    va_end(args);             // Finaliza a lista de argumentos
    return soma;
}

int main() {
    // printf("Soma 1: %d\n", soma_variavel(3, 10, 20, 30));      // Soma 10 + 20 + 30 = 60
    printf("Soma 1: %d\n", soma_variavel(3, "A", "B", "C"));      // Soma 10 + 20 + 30 = 60
    printf("Soma 2: %d\n", soma_variavel(5, 1, 2, 3, 4, 5));   // Soma 1 + 2 + 3 + 4 + 5 = 15
    return 0;
}


/*
int quantidade: é o número de argumentos variáveis que você está passando.

va_list args: tipo usado para iterar os argumentos.

va_start(args, quantidade): inicializa a lista a partir do último argumento fixo.

va_arg(args, int): acessa o próximo argumento, que deve ser do tipo int.

va_end(args): finaliza o uso da lista.
*/