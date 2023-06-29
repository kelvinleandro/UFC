#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime_data(char* data){
	printf("%c%c/%c%c/%c%c", data[0],data[1],data[2],data[3],data[4],data[5]);
}

struct ordem_servico{
    int num_os;
    char data[7];
    float valor;
    char nome_cliente[100];
    char descricao[100];
};

int main(){
    char buffer[100];

    int i, n, indice_maior;
    printf("Digite quantas ordem de servico ira ler: ");
    fgets(buffer, 100, stdin);
    n = atoi(buffer);
    
    struct ordem_servico ordens[n];
    float media_valores = 0;

    for(i=0; i < n; i++){
        setbuf(stdin, NULL);
    	printf("Numero OS: ");
        fgets(buffer, 100, stdin);
    	ordens[i].num_os = atoi(buffer);
    	
        printf("Valor: ");
        fgets(buffer, 100, stdin);
        ordens[i].valor = atof(buffer);

	    printf("Nome do cliente: ");
        fgets(ordens[i].nome_cliente, 99, stdin);

        printf("Descricao: ");
        fgets(ordens[i].descricao, 99, stdin);
        
        printf("Data (dd/mm/aa): ");
        fgets(ordens[i].data, 7, stdin);
        puts("");
    }
    
    for(i=0; i < n; i++){
		media_valores += ordens[i].valor;
		
		if(i==0){
			indice_maior = i;
		}

		else{
			if(ordens[i].valor > ordens[indice_maior].valor){
				indice_maior = i;
			}
		}
    }
    
    media_valores /= n;
    
    printf("Media dos valores dos servicos: R$%.2f\n", media_valores);
    printf("Cliente que realizou servico mais caro: %s\n", ordens[indice_maior].nome_cliente);
    printf("Descricao do produto: %s\n", ordens[i].descricao);
    printf("Data da realizacao do produto: ");
    imprime_data(ordens[indice_maior].data);
    
}
