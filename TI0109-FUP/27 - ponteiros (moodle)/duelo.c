#include <stdio.h>

struct personagem
{
    int vida, ataque;
};


int main(){
    struct personagem p1, p2;
    scanf("%d %d", &p1.vida, &p1.ataque);
    scanf("%d %d", &p2.vida, &p2.ataque);

    if((p2.vida/p1.ataque) < (p1.vida/p2.ataque)){
        printf("Personagem 1\n");
    }
    else if((p2.vida/p1.ataque) > (p1.vida/p2.ataque)){
        printf("Personagem 2\n");
    }
    else{
        printf("Empate\n");
    }
}