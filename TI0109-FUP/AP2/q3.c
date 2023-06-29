#include <stdio.h>
#include <string.h>
#define MAX 1024

int main(){
    int pontuacao = 0;
    char positivo[7][30]= { "arrochado",
                    "bichim",
                    "birita",
                    "arretado",
                    "cagado",
                    "espilicute",
                    "estribado"};

    char negativo[10][30] = { "abirobado",
                    "corno",
                    "PAIA",
                    "abestado",
                    "apapagaiado",
                    "aperrear",
                    "ariado",
                    "arrumação",
                    "babão",
                    "bocó"};
    
    char tweet[MAX];
    fgets(tweet, MAX, stdin);

    for(int i = 0; i < 7; i++){
        char *ret;

        ret = strstr(tweet, positivo[i]);
        if (ret)
            pontuacao++;
    }

    for(int i = 0; i < 10; i++){
        char *ret;

        ret = strstr(tweet, negativo[i]);
        if (ret)
            pontuacao--;
    }


    if(pontuacao > 0){
        printf("positivo");
    }
    else if(pontuacao == 0){
        printf("neutro");
    }
    else{
        printf("negativo");
    }

}