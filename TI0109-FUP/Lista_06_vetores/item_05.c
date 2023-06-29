#include <stdio.h>

int main(){
    int fibo[50], a = 0, b = 1;

    for (int i = 0; i < 50; i++){
        fibo[i] = a + b;
        a = b;
        b = fibo[i];
    }

    for (int i = 0; i < 50; i++){
        printf("fibo[%d] = %d\n", i, fibo[i]);
    }
    
}