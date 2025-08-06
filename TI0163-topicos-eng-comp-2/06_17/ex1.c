#include <stdio.h>

void inc(int *n) {
  (*n) += 1;
  //(*n)++;
}

void dec(int *n) {
    (*n) -= 1;
}

int soma(int a, int b) {
    return a + b;
}

int main(void) {

  void (*fp) (int *n); // function pointer
  int (*fp2) (int a, int b); // function pointer

  fp = inc; // inc; // fp points to inc
  fp2 = soma;
  
  int a = 0;
  printf("a vale %d\r\n", a);

  inc(&a); // call the normal function inc
  printf("a vale %d\r\n", a);

  fp(&a); // call using the function pointer
  printf("a vale %d\r\n", a);

  fp = dec;
  fp(&a); // call using the function pointer
  printf("a vale %d\r\n", a);

  int b = 3;

  printf("a + b = %d\r\n", soma(a,b));
  printf("a + b = %d\r\n", fp2(a,b));

  return 0;
}

// um ponteiro de função só pode apontar para funções que tenham o mesmo
// protótipo (assinatura) com o qual o ponteiro foi declarado.