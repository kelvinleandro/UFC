#include <stdio.h>

#define stLigado 1
#define stDesligado 0

void desligarLed(void){
    printf("LED DESLIGADO\n");
}

void ligarLed(void){
    printf("LED LIGADO\n");
}

int main(void){
    char currentState = stDesligado;
    char nextState = stLigado;
    int sensorLigar = 0;

    while(1){
        if(currentState == stDesligado) {
            desligarLed();
            printf("Ligar S(1)/N(0): ");
            scanf("%d", &sensorLigar);
            if(sensorLigar == 0) {
                nextState = currentState;
            } else {
                nextState = stLigado;
            }
        }

        if(currentState == stLigado) {
            ligarLed();
            printf("Desligar S(1)/N(0): ");
            scanf("%d", &sensorLigar);
            if(sensorLigar == 0) {
                nextState = stLigado;
            } else {
                nextState = stDesligado;
            }
        }

        currentState = nextState;
    }
    return 0;
}