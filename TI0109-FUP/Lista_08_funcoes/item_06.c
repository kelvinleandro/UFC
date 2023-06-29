#include <stdio.h>

void triangulo(int a, int b, int c){
    if ((a < b+c) && (b < a+c) && (c < a+b)){
        if ((a==b) && (b == c)){
            printf("Equilatero");
        }
        else if ((a != b) && (a != c) && (b !=c)){
            printf("Escaleno");
        }
        else{
            printf("Isosceles");
        }
    }
    else{
        printf("Nao forma triangulo");
    }
}

int main(){
    triangulo(3,4,5);
}