#include <stdio.h>

int main()
{
    int num, primo = 1,k = 2, j;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++){
        j = 2;
        while ((primo == 1) && (j < k)) {
            if (k % j == 0){
                primo = 0;
            }
            j++;
        }
        if (primo == 1) {
            printf("%d numero primo eh: %d\n", i, k);
        }
        else{
            i++;
        }
        k++;
    }
}
