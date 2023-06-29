#include <stdio.h>

int main(){
    int n, i, j, a=0, b=0, k=0, fim=0;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
    int v[n];

    for (i = 0; i < n; i++){
        printf("Digite o %do elemento: ", i+1);
        scanf("%d", &v[i]);
    }
    
    for(i=0; i<n && !fim; i++){
        for(j=i+2; j<n & !fim; j++){
            if(v[i] == v[j]){
                for(a=i, b=j, k=0; a<n && b<n && v[a]==v[b]; a++, b++, k++){
                    if (k > 1){
                        a = a-k;
                        b = b - k;
                        fim = 1;
                    }
                }
            }
        }
    }

    printf("i = %d\n", a+2);
    printf("m = %d\n", k);
}