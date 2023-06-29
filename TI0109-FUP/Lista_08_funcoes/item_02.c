#include <stdio.h>

float calcula(float x, float y, char op){
    switch (op){
        case 'a':
            return x+y;
        case 's':
            return x-y;
        case 'm':
            return x*y;
        case 'd':
            return x/y;
    }
}

int main(){
    float res = calcula(2,3,'a');
    printf("%f",res);
}