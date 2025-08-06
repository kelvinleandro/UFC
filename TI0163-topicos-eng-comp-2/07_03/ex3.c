#include <stdio.h>
#include "ex3_funcoes.h"

int main(void) {
  float f1 = 0.0;
  float f2 = 0.0;
  float f3 = 0.0;
  float f4 = 0.0;
  int i = 0;

  f1 = 6.0;
  f2 = 4.0;

  f3 = soma(f1, f2);
  f4 = sub(f1, f2);

  printf("f1 = %f e f2 = %f\n", f1, f2);	

  printf("f1 + f2 = %f\r\n", f3);

  printf("f1 - f2 = %f\r\n", f4);

  return 0;
}
