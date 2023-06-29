#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int result;
    for (int i = 1; i <= 20; i++){
        result = pow(i, 2);
        printf("%d ** 2 = %d\n", i, result);
    }
    
    return 0;
}
