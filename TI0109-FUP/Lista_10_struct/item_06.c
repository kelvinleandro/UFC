#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TOMBO 20

struct data{
  int dia,mes,ano;
};

struct obra{
    int num_tombo;
    int num_exemplar;
    struct data data_compra;
};

struct tombo{
    int num_tombo;
    char nome_obra[100];
    char nome_autor[100];
    char nome_editora[100];
    int ano;
    int quant_obras;
    struct obra *obras[3];
};

void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");

  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

struct tombo* procuraTomboPorNum(struct tombo* tombos, int qntdTombos, int num_tombo){
    for(int i = 0; i < qntdTombos; i++){
        if(tombos[i].num_tombo == num_tombo){
            return &tombos[i];
        }
    }
    return NULL;
}

bool verificaSeExisteNumeroDoTombo(struct tombo* tombos, int quant_tombos, int num_tombo){
    return procuraTomboPorNum(tombos, quant_tombos, num_tombo) != NULL;
}

struct tombo* associaObraATombo(struct tombo* tombos, int qntdTombos, int numTombo, struct obra* obra){
    int quant_obras = 0;
    struct tombo* associar = procuraTomboPorNum(tombos, qntdTombos, numTombo);
    if(associar){
        quant_obras = associar->quant_obras;
        if(quant_obras < 3){
            associar->obras[quant_obras] = obra;
            associar->quant_obras++;
            return associar;
        } 
    }
    return NULL;
}

void imprimeData(const struct data* data){
    printf("%02d/%02d/%d\n", data->dia, data->mes, data->ano);
}


void imprimeObra(const struct obra* obra){
    printf("DATA DE COMPRA: ");
    imprimeData(&(obra->data_compra));
    printf("NUMERO DO EXEMPLAR: %d\n",obra->num_exemplar);
    printf("NUMERO DO TOMBO: %d\n", obra->num_tombo);
}

void imprimeObrasDeTombo(const struct tombo* tombo){
    for(int i = 0; i < tombo->quant_obras; i++){
        imprimeObra(tombo->obras[i]); 
    }
}

int main(){
    char buffer[100];
    struct tombo tombos[MAX_TOMBO];
    int quant_tombos = 0, quant_obras = 0;
    bool existeTombo = false;
    bool obraAssociada = false;
    bool continuar = false;

    //cadastro dos tombos
    for(quant_tombos=0; quant_tombos < MAX_TOMBO && continuar; quant_tombos++){
        printf("Tombo %d:\n", quant_tombos+1);
        printf("Digite o nome da obra: ");
        fgets(tombos[quant_tombos].nome_obra, 100, stdin);

        printf("Digite o nome do autor: ");
        fgets(tombos[quant_tombos].nome_autor, 100, stdin);

        printf("Digite o nome da editora: ");
        fgets(tombos[quant_tombos].nome_editora, 100, stdin);

        printf("Digite o ano: ");
        tombos[quant_tombos].ano = atoi(fgets(buffer, 100, stdin));

        do{
            printf("Digite o numero do tombo: ");
            tombos[quant_tombos].num_tombo = atoi(fgets(buffer, 100, stdin));
            existeTombo = verificaSeExisteNumeroDoTombo(tombos, quant_tombos, tombos[quant_tombos].num_tombo);
            if(existeTombo){
                printf("Numero de tombo ja cadastrado, digite novamente.\n");
            }
        }while(existeTombo);
        tombos[quant_tombos].quant_obras = 0;

        printf("Deseja cadastrar mais um tombo? sim para continuar, qualquer outra coisa para cancelar");
        fgets(buffer, 100, stdin);
        if(strcmp(buffer, "sim\n") != 0) continuar = false;
    }

    //cadastro de obras
    int max_obras = quant_tombos*3;
    struct obra obras[max_obras];
    continuar = true;
    for(quant_obras=0; quant_obras < max_obras && continuar; quant_obras++){
        printf("Obra %d:\n", quant_obras+1);
        do{
            printf("Numero do tombo: ");
            mostraNumeroDosTombosDisponiveis(tombos, quant_tombos);
            obras[quant_obras].num_tombo = atoi(fgets(buffer,100, stdin));
            existeTombo = verificaSeExisteNumeroDoTombo(tombos, quant_tombos, obras[quant_obras].num_tombo);

            if(!existeTombo){
                printf("Tombo nao existe, digite novamente.\n");
            }else{
                obraAssociada = associaObraATombo(tombos, quant_tombos, obras[quant_obras].num_tombo, &obras[quant_obras]);
                if(!obraAssociada){
                    printf("Tombo esta com a quantidade maxima de obras.");
                }
            }
        }while(!existeTombo || !obraAssociada);

        printf("Digite a data de compra da obra no formato DD/MM/AAAA: ");
        converteData(fgets(buffer,100,stdin), &(obras[quant_obras].data_compra)); 
        obras[quant_obras].num_exemplar = procuraTomboPorNum(tombos, quant_tombos, obras[quant_obras].num_tombo)->quant_obras;

        printf("Deseja cadastrar mais uma obra? sim para continuar, qualquer outra coisa para parar");
        fgets(buffer,150,stdin);
        if(strcmp(buffer, "sim\n") != 0) continuar = false;
    }
    
    //MOSTRANDO OBRAS POR ANO  
    printf("Digite o ano que voce deseja mostrar as obras: ");
    int anoDeProcura = atoi(fgets(buffer,100,stdin));
    for(int i = 0; i < quant_tombos; i++){
        if(tombos[i].ano == anoDeProcura){
            imprimeObrasDeTombo(&tombos[i]);
        }
    }
    //MOSTRA OBRAS POR AUTOR
    printf("Digite o autor que voce deseja mostrar as obras: ");
    char autor[100];
    fgets(autor, 100, stdin);
    for(int i = 0; i < quant_tombos; i++){
        if(strcmp(autor,tombos[i].nome_autor) == 0){
            imprimeObrasDeTombo(&tombos[i]);
        }
    }

    //MOSTRA OBRAS POR EDITORA
    printf("Digite a editora que voce deseja mostrar as obras: ");
    char editora[100];
    fgets(editora, 100, stdin);
    for(int i = 0; i < quant_tombos; i++){
        if(strcmp(autor,tombos[i].nome_editora) == 0){
            imprimeObrasDeTombo(&tombos[i]);
        }
    }

    return 0;
    
}