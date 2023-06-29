#include <stdio.h>
#include <math.h>

int is_cont(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    for(i=0 ; i < n; i++){
        for(j=0; j < m; j++){
            if(arr2[i] == arr1[j]){
                break;
            }
        }

        if(j == m)
            return 0;
    }

    return 1;
}

int main(){
    int n, m;
    printf("Quantos elementos tera o vetor a: ");
    scanf("%d", &n);
    printf("Quantos elementos tera o vetor b: ");
    scanf("%d", &m);
    int vet_a[n], vet_b[m];

    printf("Preencha o vetor A:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &vet_a[i]);
    }

    printf("Preencha o vetor B:\n");
    for(int i = 0; i < m; i++){
        scanf("%d", &vet_b[i]);
    }

    int res = is_cont(vet_b, vet_a, m, n);
    if(res){
        printf("A esta contido em B");
    }
    else{
        printf("A nao esta contido em B");
    }
}