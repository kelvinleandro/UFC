#include <stdio.h>

int main(){
    int fat;
    float x, s = 0;
    printf("Digite um valor: ");
    scanf("%f", &x);

    for (int i = 1; i <= 20; i++){
        fat = 1;
        for (int j = 2; j <= i-1; j++){
            fat = fat * j;
        }

        if (i % 2 == 0){
            s = s - (x / fat);
        }
        else {
            s = s + (x / fat);
        }
	}

	printf("Somatorio = %.2f", s);
}
