#include <stdio.h>

int main(){
    int quant;
    printf("Quantos numeros deseja ver? ");
    scanf("%d", &quant);

    for (int i = 1; i <= quant; i++){
    	printf("%d\n", i*i);
	}
}
