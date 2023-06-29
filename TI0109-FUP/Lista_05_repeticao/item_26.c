#include <stdio.h>

int main(){
    int n;
    printf("Quantos numeros deseja ver? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
    	if (i % 3 == 1){
            printf("%d\n", (i/3)+1);
    	}
    	else if(i % 3 == 2){
            printf("%d\n", (i/3)+4);
    	}
    	else{
            printf("%d\n", (i/3)+3);
    	}
	}
}
