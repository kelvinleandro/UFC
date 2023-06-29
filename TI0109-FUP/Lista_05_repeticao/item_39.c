#include <stdio.h>

int main()
{
    int a = 5000000, b = 7000000;
    int t_neces = 0;
    
    while (a < b){
        a = a + a*0.03;
        b = b + b*0.02;
        t_neces++;
    }
    
    printf("Tempo necessario = %d anos.", t_neces);
}
