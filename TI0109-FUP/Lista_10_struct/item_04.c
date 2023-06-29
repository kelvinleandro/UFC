#include <stdio.h>
#include <stdlib.h>
#define quant 2

struct data{
  int dia,mes,ano;
};

struct boleto{
	int documento;
	int cod_cliente;
	struct data vencimento;
	struct data pagamento;
	float valor, juros;
};

void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");

  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

double calcula_juros(struct boleto conta){
	struct data pagamento = conta.pagamento;
	struct data vencimento = conta.vencimento;
	int diasPagamento = pagamento.ano*365 + pagamento.mes*30 + pagamento.dia;
	int diasVencimento = vencimento.ano*365 + vencimento.mes*30 + vencimento.dia;

	return diasPagamento > diasVencimento ? (diasPagamento - diasVencimento)*0.0002 : 0;
}

int main(){
	struct boleto contas[quant];
	char buffer[100];
	double valor_arrecadado = 0;
	int i;

	for(i=0; i < quant; i++){
		printf("Valor do boleto: ");
		contas[i].valor = atof(fgets(buffer, 100, stdin));

		printf("Codigo do cliente: ");
		contas[i].cod_cliente = atoi(fgets(buffer, 100, stdin));

		printf("Numero do documento: ");
		contas[i].documento = atoi(fgets(buffer, 100, stdin));

		printf("Data do pagamento (DD/MM/AAAA): ");
		fgets(buffer, 100, stdin);
		converteData(buffer, &contas[i].pagamento);

		printf("Data do vencimento (DD/MM/AAAA): ");
		fgets(buffer, 100, stdin);
		converteData(buffer, &contas[i].vencimento);
		
		contas[i].juros = calcula_juros(contas[i]);
		valor_arrecadado += contas[i].valor * contas[i].juros;

	}

	printf("TOTAL ARRECADA EM JUROS: R$%.2lf\n", valor_arrecadado);

}
