#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    printf("Digite a idade: ");
    scanf("%d", &idade);

    //analisa idade e printa a categoria
    if (idade >= 5 && idade <= 7) {
        printf("Categoria: Infantil");
    }
    else if (idade >= 8 && idade <= 10) {
        printf("Categoria: Infanto-juvenil");
    }
    else if (idade >= 11 && idade <= 15) {
        printf("Categoria: Juvenil");
    }
    else if (idade >= 16 && idade <= 30) {
        printf("Categoria: Adulto");
    }
    else if (idade > 30) {
        printf("Categoria: Master");
    }
    else {
        printf("Erro.");
    }
}
