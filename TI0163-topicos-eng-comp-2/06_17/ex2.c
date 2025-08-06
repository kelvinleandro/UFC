#include <stdio.h>

int soma(int a, int b) { return a + b; }

int multiplica(int a, int b) { return a * b; }

typedef int (*Operacao)(int a, int b);

// Executa uma operação binária sobre dois operandos
int opera(int a, int b, Operacao op) { return op(a, b); }

int main() {
  printf("%d\n", opera(5, 7, soma));       // imprime 12
  printf("%d\n", opera(5, 7, multiplica)); // imprime 35
}