#include <stdio.h>

int main(){
    int n;
    float s = 0;
    printf("Digite um valor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        s = s + i / (n - i + 1);
    }

    printf("S = %.2f", s);
}
