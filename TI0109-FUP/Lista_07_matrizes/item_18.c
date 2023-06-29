#include <stdio.h>

int main(){
    int i, j, quant_alunos= 3;
    int alunos[quant_alunos][4], cod_curso, maior_rend, mat;

    for(i = 0; i < quant_alunos; i++){
        for(j = 0; j < 4; j++){
            if(j == 0){
                printf("Matricula do aluno %d: ", i+1);
                scanf("%d", &alunos[i][j]);
            }
            else if(j == 1){
                printf("Sexo do aluno %d [0-femin. / 1-masc.]: ", i+1);
                scanf("%d", &alunos[i][j]);
            }
            else if(j == 2){
                printf("Codigo de curso do aluno %d: ", i+1);
                scanf("%d", &alunos[i][j]);
            }
            else{
                printf("Coeficiente de rendimento do aluno %d: ", i+1);
                scanf("%d", &alunos[i][j]);
            }
        }
    }

    printf("\nDigite o codigo do curso para premiar uma aluna: ");
    scanf("%d", &cod_curso);

    for(i=0; i< quant_alunos; i++){
        if((alunos[i][1] == 0) && (alunos[i][2] == cod_curso)){
            if(alunos[i][3] >= maior_rend){
                maior_rend = alunos[i][3];
                mat = i;
            }
        }
    }

    for(i=0; i < quant_alunos; i++){
        if((alunos[i][1] == 0) && (alunos[i][2] == cod_curso)){
            if(alunos[i][3] == maior_rend){
                printf("Aluna do curso %d com o maior CR: %d\n", cod_curso, alunos[i][0]);
            }
        }
    }
}
