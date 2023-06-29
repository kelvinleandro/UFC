#include <stdio.h>

int main()
{
    int quant, voto = 1, ze = 0, gal = 0, gil = 0;
    for (int i = 1; voto != 0; i++){
        printf("Para quem voce ira votar:\n ");
        printf("1 - ZE\n 2 - GAL\n 3 - GIL\n 0 - Encerra votacao\n");
        scanf("%d", &voto);
        if (voto == 1) {
            ze++;
        }
        else if (voto == 2){
            gal++;
        }
        else if (voto == 3){
            gil++;
        }
        else if (voto != 0){
            printf("Opcao invalida");
        }
    }
    
    if ((ze > gal) && (ze > gil)){
        printf("Vencedor : ZE");
    }
    else if ((gal > ze) && (gal > gil)){
        printf("Vencedor : GAL");
    }
    else if ((gil > ze) && (gil > gal)){
        printf("Vencedor : GIL");
    }
    else {
        printf("Ocorreu um empate");
    }
    
}
