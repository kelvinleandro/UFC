#include <stdio.h>

long int fat(int n){
    long int res = 1;
    for(res = 1; n > 1; n = n - 1){
        res = res * n;
    }
}

int main(){
    long int test = fat(10);
    printf("%ld", test);
}