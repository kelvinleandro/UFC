#include <stdio.h>
#include <stdbool.h>
#define quant 2

struct produto{
	char descricao[100];
	int codigo, quantidade;
	float valor;
};

void ordena_vetor(struct produto* produtos){
	int i, j;
	struct produto aux;
	
	for(i = 0; i < quant; i++){
        for(j = i + 1; j < quant; j++){
            if(produtos[i].codigo > produtos[j].codigo){
                aux = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = aux;
            }
        }
    }
	
}

void imprime_vetor(struct produto* v, int i){
	printf("Descricao: %s", v[i].descricao);
	printf("\nValor: R$%.2f\n", v[i].valor);
	printf("Estoque: %d\n", v[i].quantidade);
	printf("Codigo: %d\n", v[i].codigo);
}

int main(){
	struct produto produtos[quant];
	int i, j;
	bool codigoRepetido;
	char buffer[100];
	
	for(i=0; i < quant; i++){
		do{
			codigoRepetido = false;
			printf("Codigo do produto: ");
			produtos[i].codigo = atoi(fgets(buffer, 100, stdin));
			
			for(j = 0; j < i && !codigoRepetido; j++){
				if(produtos[i].codigo == produtos[j].codigo){
          			codigoRepetido = true;
        		}
			}
		}while(codigoRepetido);
		
		printf("Valor do produto: ");
		produtos[i].valor = atof(fgets(buffer, 100, stdin));
		
		printf("Quantidade em estoque: ");
		produtos[i].quantidade = atoi(fgets(buffer, 100, stdin));
		
		printf("Descricao do produto: ");
		fgets(produtos[i].descricao, 100, stdin);
		puts("");
	}

	ordena_vetor(produtos);

	for(i=0; i < quant; i++){
		printf("Produto %d de %d: \n", i+1, quant);
		imprime_vetor(produtos, i);
	}

	return 0;
}