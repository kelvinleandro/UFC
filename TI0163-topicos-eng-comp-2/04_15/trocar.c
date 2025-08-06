#include <stdio.h>
void trocar ( int a , int b) {
    int temp ;
    temp = a; a = b; b = temp ;
}
int main (void) {
    int a = 10 , b = 20;
    trocar (a , b);
    printf ("a = %d , b = %d\n ", a , b) ;
    return 0;
}