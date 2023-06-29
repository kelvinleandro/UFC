#include <stdio.h>

int pot(int x, int z){
    int res = 0;
    if(z==0){
        return 1;
    }

    for(int i = 1; i < z; i++){
        return x*x;
    }

    return x;
}

int main(){
    int test = pot(2, 2);
    printf("%d", test);
}