#include <stdio.h>

int main()
{
    int nums[100];
    int num = 200;
    for (int i = 0; i < 100; i++){
        nums[i] = num;
        num--;
    }
    
    for (int i = 0; i < 100; i++){
        printf("nums[%d] = %d\n", i, nums[i]);
    }
}
