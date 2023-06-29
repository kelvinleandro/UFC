#include <stdio.h>

int numInvert(unsigned int n){
    int quant_digits = floor(log10(n)) + 1;
    int decomposto[quant_digits], result = 0;

    for (int i = quant_digits-1; i >=0; i--){
        decomposto[i] = n%10;
        n /= 10;
    }

    for(int i=quant_digits-1; i >= 0; i--){
        result = result*10 + decomposto[i];
    }
}

int main(){
    printf("%d", numInvert(123));
}