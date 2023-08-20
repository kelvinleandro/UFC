#include <stdio.h>
#include <string.h>

void add_n_count(char tweet[], char file_name[]){
    FILE* file = fopen(file_name, "w");
    char ch;
    int lines = 0;

    if(file == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
    else{
        fprintf(file, "%s", tweet);
        printf("Conteudo adicionado com sucesso no arquivo.\n");
    }

    while((ch=fgetc(file))!=EOF) {
        if(ch=='\n') lines++;
    }

    printf("Quantidade de linhas: %d", lines);
}

int main(){
    char tweet[100];
    char file_name[100];

    printf("Tweet:\n");
    fgets(tweet, 100, stdin);
    printf("Nome do arquivo txt (sem espacos):\n");
    fgets(file_name, 100, stdin);

    file_name[strcspn(file_name, "\n")] = 0;
    add_n_count(tweet, file_name);

    return 0;
}