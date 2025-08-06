#include <stdio.h>
#include "soma.h"

int main(void){
    int a=1, b=2, c;

    c = soma(a,b);
    printf("soma(%d, %d) = %d\n", a, b, c);
    
    return 0;
}