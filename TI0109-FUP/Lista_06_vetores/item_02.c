#include <stdio.h>

int main()
{
    int nums[100];
    for (int i = 0; i < 100; i++){
        nums[i] = (i+1) * 5;
    }
    
    for (int i = 0; i < 100; i++){
        printf("nums[%d] = %d\n", i, nums[i]);
    }
}
