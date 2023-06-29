#include <stdio.h>
#include <stdlib.h>

int main()
{
    int q_alunos;
    float notas, media, n1, n2;
    printf("De quantos alunos voce deseja calcular as medias? ");
    scanf("%d", &q_alunos);
    
    for (int i = 1; i <= q_alunos; i++){
        printf("Digite a primeira nota: ");
        scanf("%f", &n1);
        printf("Digite a segunda nota: ");
        scanf("%f", &n2);
        media = (n1 + n2) / 2;
        printf("Media do %do aluno = %.1f\n", i, media);
    }
}
