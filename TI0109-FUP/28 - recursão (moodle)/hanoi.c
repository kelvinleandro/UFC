#include <stdio.h>

void hanoi(int quant, char ini, char aux, char fim){
    if(quant == 1)
        printf("%c -> %c\n", ini, fim);
    else{
        hanoi(quant-1, ini, fim, aux);
        printf("%c -> %c\n", ini, fim);
        hanoi(quant-1, aux, ini, fim);
    }
}

int main(){
    int quant;
    scanf("%d", &quant);
    hanoi(quant, 'A', 'B', 'C');
}