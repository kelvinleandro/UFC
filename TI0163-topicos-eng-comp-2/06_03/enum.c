#include <stdio.h>

enum days {segunda, terca, quarta, quinta, sexta, sabado, domingo};

int main(void){
    enum days dia;
    int hoje;

    while(1) {
        printf("\nQ dia eh hj: ");
        scanf("%d", &hoje);
        dia = hoje;

        if (dia == sexta) {
            printf("sextou\n");
            return 0;
        }
    }
}