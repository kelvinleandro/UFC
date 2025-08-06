#include <stdio.h>

int main(void){
    int i = 10;

    int *p;
    p = &i;

    printf("%d\n", i);
    printf("END i = %p\n", &i);
    printf("END i = %p\n", p);
    printf("END p = %p\n", &p);
    return 0;
}