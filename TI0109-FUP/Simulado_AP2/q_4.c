#include <stdio.h>
#define MAX 11
#define LIM 25

void decifra(int v[], int index, char alfabeto[]){
    for(int i = index; i < MAX; i++){
        if(v[i] > 25) break;
        
        printf("%c", alfabeto[v[i]]);
    }
}

int main(){
    int v[MAX], quant_pares = 0;
    char letras[26] = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < MAX; i++){
        scanf("%d", &v[i]);

        if(v[i] % 2 == 0) quant_pares++;
    }

    decifra(v, quant_pares, letras);
}