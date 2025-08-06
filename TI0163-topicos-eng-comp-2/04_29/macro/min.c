#include <stdio.h>
// #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MIN(a, b, c) ((a < b) ? a : b)

int main(void){
    int a = 18;
    int b = 76;
    printf("Minimum value between %d and %d is %d\n", a, b, MIN(a, b));
    
    return 0;
}