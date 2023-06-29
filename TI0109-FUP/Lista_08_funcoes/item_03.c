#include <stdio.h>

int converteTempo(int numHoras, char tipo){
    switch (tipo){
        case 'h':
            return numHoras;
        case 'm':
            return numHoras*60;
        case 's':
            return numHoras*3600;
    }
}

int main(){
    int res = converteTempo(3, 's');
    printf("%d", res);

    return 0;
}