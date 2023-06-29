#include <stdio.h>

int main(){
    int n, j = 0, nvezes = 1, anterior;
    printf("Digite um valor para n: ");
    scanf("%d", &n);
    int nums[n], vetsrp[n];

    printf("Digite os valores do vetor em ordem crescente:");
    for (int i = 0; i < n; i++){
        printf("\nDigite um numero: ");
        scanf("%d", &nums[i]);
    }

    anterior = nums[0];
    vetsrp[0] = nums[0];

    for (int i = 1; i < n; i++){
        if (nums[i] == anterior){
            nvezes++;
        }
        else{
            printf("O numero %d se repete %d vezes\n", anterior, nvezes);
            j++;
            vetsrp[j] = nums[i];
            anterior = nums[i];
            nvezes = 1;
        }
    }

    printf("O numero %d se repete %d vezes\n", anterior, nvezes);
    printf("O vetor sem numeros repetidos eh:\n ");
    for (int i = 0; i < j; i++){
        printf("%d ", vetsrp[i]);
    }

}
