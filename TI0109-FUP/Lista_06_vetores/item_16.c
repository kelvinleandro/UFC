#include <stdio.h>
#include <math.h>

int main(){
    int q_alunos, i, j, acertos, q_questoes = 5;
    char aluno_itens, gabarito[q_questoes];

    // quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &q_alunos);

    // preenche o gabarito
    printf("Preencha o gabarito oficial:");
    for(i = 0; i < q_questoes; i++){
        printf("\nDigite a resposta da questao %d: ", i+1);
        scanf("%c", &gabarito[i]);
    }

    // preenche e verifica gabarito dos alunos
    for(i = 0; i < q_alunos; i++){
        acertos = 0;
        printf("\nGabarito do Aluno %d:", i+1);
        for(j = 0; j < 30; j++){
            printf("\nDigite a resposta da questao %d: ", i+1);
            scanf("%c", &aluno_itens);
            if (aluno_itens == gabarito[j]){
                acertos++;
            }
        }
        printf("O Aluno %d marcou %d acertos.\n", i+1, acertos);
    }
}