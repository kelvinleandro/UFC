#include <stdio.h>

void parts_num(float n){
    printf("Parte inteira = %d", (int)n);
    printf("Parte fracionada = %.2f", n - (int)n);
}

int main(){
    parts_num(1.7);
}