#include <stdio.h>

int main(){
    int nums[10], impar = 1;
    for (int i = 0; i < 10; i++){
        nums[i] = impar * impar;
        impar += 2;
    }

    for (int i = 0; i < 10; i++){
        printf("nums[%d] = %d\n", i+1, nums[i]);
    }
}