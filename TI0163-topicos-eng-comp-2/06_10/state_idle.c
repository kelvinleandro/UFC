#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    IDLE,
    PROCESSING,
    DONE
} State;

int main(void){
    int i = 0;
    State currentState;
    currentState = IDLE;

    while(1){
        switch(currentState){
            case IDLE:
                printf("IDLE\r\n");
                scanf("%d", &i);
                if (i == 1){
                    currentState++;
                }
                break;
            case PROCESSING:
                printf("PROCESSING\r\n");
                currentState++;
                sleep(2);
                break;
            case DONE:
                printf("DONE\r\n");
                currentState = 0;
                sleep(2);
                system("clear");
                break;
        }
    }

    
    return 0;
}