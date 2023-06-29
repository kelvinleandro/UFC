#include <stdio.h>
#include <math.h>

int main(){
    double conj[100], soma = 0;

    for(int i = 0; i < 100; i++){
        printf("Digite um valor: ");
        scanf("%lf", &conj[i]);
    }

    for(int i = 0; i < 50; i++){
        soma = soma + pow(conj[i] - conj[99-i],3);
    }

    printf("Somatorio = %lf", soma);
}
