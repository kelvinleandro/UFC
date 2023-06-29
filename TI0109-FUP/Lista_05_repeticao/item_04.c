#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int result, n;
    printf("Quantas potencias voce deseja ver? ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        result = pow(i, 2);
        printf("%d ** 2 = %d\n", i, result);
    }
    
    return 0;
}
