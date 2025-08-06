#include <stdio.h>

int main(void) {
  float f1 = 0.0;
  float f2 = 0.0;
  float f3 = 0.0;
  int i = 0;

  f1 = 1.0;
  f2 = 2.0;
  f3 = f1 + f2;

  printf("f1 + f2 = %f\r\n", f3);

  for (i = 0; i < 10; i++) {
    printf("Valor de i = %d\r\n", i);
  }

  return 0;
}
