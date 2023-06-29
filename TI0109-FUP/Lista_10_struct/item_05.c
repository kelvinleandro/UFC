#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define q_estilista 5
#define q_estacoes 4
#define q_roupas 10

struct estilista{
    int codigo;
    char nome[100];
    double salario;
};

struct estacao{
    int codigo;
    char nome[100];
};

struct roupa{
    int codigo;
    char descricao[100];
    int cod_estilista;
    int cod_estacao;
    int ano;
};

void imprimeRoupa(struct roupa roupa){
    printf("-------------------------------------------------------------------\n");
    printf("DESCRICAO: %s", roupa.descricao);
    printf("CODIGO DA ROUPA: %d\n", roupa.codigo);
    printf("CODIGO DO ESTILISTA: %d\n", roupa.cod_estilista);
    printf("CODIGO DA ESTACAO: %d\n", roupa.cod_estacao);
    printf("ANO DE LANCAMENTO: %d\n", roupa.ano);
    printf("-------------------------------------------------------------------\n");
}

int main(){
    char buffer[100];
    bool codigoRepetido, nomeRepetido;
    bool estilistaExiste, estacaoExiste;
    struct estilista estilistas[q_estilista];
    struct estacao estacoes[q_estacoes];
    struct roupa roupas[q_roupas];
    int i, j;

    printf("Cadastro de estacoes:\n");
    for(i=0; i < q_estacoes; i++){
        //cadastra o nome das estacoes
        do{
            nomeRepetido = false;
            printf("Digite o nome da estacao: ");
            fgets(estacoes[i].nome, 100, stdin);

            //verifica se a estacao ja existe
            for(j=0; j < i && !nomeRepetido; j++){
                if(strcmp(estacoes[i].nome, estacoes[j].nome) == 0){
                    printf("Nome ja existe. Digite outro.\n");
                    nomeRepetido = true;
                }
            }
        }while(nomeRepetido);

        //cadastra o codigo das estacoes
        do{
            codigoRepetido = false;
            printf("Digite o codigo da estacao: ");
            estacoes[i].codigo = atoi(fgets(buffer, 100, stdin));

            //verifica se o codigo da estacao ja existe
            for(j = 0; j < i && !codigoRepetido; j++){
                if(estacoes[i].codigo == estacoes[j].codigo){
                    printf("Codigo ja existe Digite outro.\n");
                    codigoRepetido = true;
                }
            }
        }while(codigoRepetido);
    }

    printf("Cadastro dos estilistas:\n");
    for(i=0; i < q_estilista; i++){
        //cadastra o nome dos estilista
        nomeRepetido = false;
        printf("Digite o nome do estilista %d: ", i+1);
        fgets(estilistas[i].nome, 100, stdin);

        //cadastra o codigo dos estilistas
        do{
            codigoRepetido = false;
            printf("Digite o codigo do estilista: ");
            estilistas[i].codigo = atoi(fgets(buffer, 100, stdin));

            //verifica se o codigo do estilista ja existe
            for(j = 0; j < i && !codigoRepetido; j++){
                if(estilistas[i].codigo == estilistas[j].codigo){
                    printf("Codigo ja existe. Digite outro.\n");
                    codigoRepetido = true;
                }
            }
        }while(codigoRepetido);

        //recebe o salario do estilista
        printf("Digite o salario do estilista: R$");
        estilistas[i].salario = atoi(fgets(buffer, 100, stdin));
    }

    printf("Cadastro das roupas:\n");
    for(i=0; i < q_roupas; i++){
        //descricao da roupa
        printf("Descricao da roupa %d: ", i+1);
        fgets(roupas[i].descricao, 100, stdin);

        //cadastra o codigo das roupas
        do{
            codigoRepetido = false;
            printf("Digite o codigo da roupa: ");
            roupas[i].codigo = atoi(fgets(buffer, 100, stdin));

            //verifica se o codigo da roupa ja existe
            for(j = 0; j < i && !codigoRepetido; j++){
                if(roupas[i].codigo == roupas[j].codigo){
                    printf("Codigo ja existe. Digite outro.\n");
                    codigoRepetido = true;
                }
            }
        }while(codigoRepetido);

        //ATRIBUI ESTILISTA A ROUPA 
        do{
            estilistaExiste = false;
            printf("Digite o codigo do estilista: ");
            roupas[i].cod_estilista = atoi(fgets(buffer, 100, stdin));

            //verifica se estilista existe
            for(j = 0; j < q_estilista; j++){
                if(roupas[i].cod_estilista == estilistas[j].codigo){
                    estilistaExiste = true;
                }
            }
            if(!estilistaExiste){
                printf("Estilista nao existe. Digite outro.");
            }
        }while(!estilistaExiste);

        //ATRIBUI ESTACAO A ROUPA
        do{
            estacaoExiste = false;
            printf("Digite o codigo da estacao: ");
            roupas[i].cod_estacao = atoi(fgets(buffer, 100, stdin));

            //verifica se estilista existe
            for(j = 0; j < q_estacoes && !estacaoExiste; j++){
                if(roupas[i].cod_estacao == estacoes[j].codigo){
                    estacaoExiste = true;
                }
            }
            if(!estacaoExiste){
                printf("Estilista nao existe. Digite outro.");
            }
        }while(!estacaoExiste);
        
        //recebe o ano da roupa
        printf("Digite o ano da roupa: ");
        roupas[i].ano = atoi(fgets(buffer, 100, stdin));
    }

    int codigoEstacao = 0;
    do{
        printf("Digite a estacao das roupas que deseja ver: ");
        fgets(buffer, 100, stdin);

        //verifica se estacao existe
        for(j=0; j < q_estacoes; j++){
            if(strcmp(buffer, estacoes[j].nome) == 0){
                codigoEstacao = estacoes[i].codigo;
                estacaoExiste = true;
            }
        }
        if(!estacaoExiste){
            puts("Estacao nao existe. Digite novamente.");
        }
    }while(!estacaoExiste);

    //imprime as roupas
    for(i=0; i < q_roupas; i++){
        if(roupas[i].codigo == codigoEstacao){
            imprimeRoupa(roupas[i]);
        }
    }

}