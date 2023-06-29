#include <stdio.h>

int main(){
    int n, k, i, j, aux;
    
    // le valor n
    printf("Digite um valor para N: ");
    scanf("%d", &n);
    int nums[n];

    printf("Digite o k-esimo elemento que deseja ver antes e depois da ordenacao : ");
    scanf("%d", &k);

    // valores para vetor de n posicoes
    for(i = 0; i < n; i++){
        printf("Digite um valor: ");
        scanf("%d", &nums[i]);
    }

    printf("\nk-esimo elemento antes da ordenacao: %d", nums[k-1]);

    // ordenar em forma crescente
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                aux = nums[i];
                nums[i] = nums[j];
                nums[j] = aux;
            }
        }
    }

    // vetor ordenado
    printf("\nVetor ordenado:\n");
    for(i = 0; i < n; i++){
        printf("%d ", nums[i]);
    }

    printf("\nk-esimo elemento depois da ordenacao: %d", nums[k-1]);

}