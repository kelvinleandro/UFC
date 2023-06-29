#include <stdio.h>

int main(){
    int n;
    float h = 0;
    printf("Digite um numero? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
    	h += 1.0/i;
	}

	printf("Valor de H = %.2f", h);
}
