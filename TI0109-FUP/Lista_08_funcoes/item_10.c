#include <stdio.h>
#include <math.h>

int arredonda(double x){
    int res = round(x);
    return res;
}

int main(){
    int test = arredonda(-1.5);
    printf("%d", test);
}