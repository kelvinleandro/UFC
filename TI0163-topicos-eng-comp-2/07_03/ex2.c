#include <stdio.h>

float soma(float f1, float f2){
	return f1 + f2;
}

int main(void) {
  float f1 = 0.0;
  float f2 = 0.0;
  float f3 = 0.0;

  f1 = 1.0;
  f2 = 2.0;

  f3 = soma(f1, f2);

  printf("f1 + f2 = %f\r\n", f3);

  for (int i = 0; i < 10; i++) {
    printf("Valor de i = %d\r\n", i);
  }

  return 0;
}
