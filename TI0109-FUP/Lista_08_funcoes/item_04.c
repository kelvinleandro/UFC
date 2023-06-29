#include <stdio.h>

int eVogal(char letra){
    char vogais[5]= {'a','e','i','o','u'};
    for(int i =0; i<5; i++){
        if (letra == vogais[i]){
            return 1;
        }
    }

    return 0;
} 

int main(){
    if(eVogal('a')){
        printf("Eh vogal");
    }
    else{
        printf("Nao eh vogal");
    }
    
}