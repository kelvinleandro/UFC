#include <stdio.h>
#include "soma.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main(void){
    int a, b;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    printf("soma = %d\n", soma(a,b));
    printf("sub = %d\n", sub(a,b));
    printf("mul = %d\n", mul(a,b));
    printf("div = %d\n", div(a,b));
}