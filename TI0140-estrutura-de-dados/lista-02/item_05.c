#include <stdio.h>

void mais_distante(int arr[], int n){
    int dif = -1, res, num1, num2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res = abs(arr[i] - arr[j]);
            if(res > dif){
                dif = res;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("%d e %d", num1, num2);
}

int main(){
    int l[] = {16,19,41,8,42,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);
    // saida esperada: 8 e 48
    mais_distante(l, n);
}
