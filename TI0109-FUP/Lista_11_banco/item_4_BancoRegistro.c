#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int num_conta;
    float saldo;
}conta_bancaria;

void creditar(int n, conta_bancaria contas[n], int num_conta, float valor){
    for(int i=0; i < n; i++){
        if(num_conta == contas[i].num_conta){
            contas[i].saldo += valor;
            return;
        }
    }

    printf("Conta nao existe.\n\n");
}

void debitar(int n, conta_bancaria contas[n], int num_conta, float valor){
    for(int i=0; i < n; i++){
        if((num_conta == contas[i].num_conta) && (valor <= contas[i].saldo)){
            contas[i].saldo -= valor;
            return;
        }
    }

    printf("Erro na operacao\n\n");
}

void transferir(int n, conta_bancaria contas[n], int conta_origem, int conta_destino, float valor){
    for(int i=0; i < n; i++){
        if((conta_origem == contas[i].num_conta) && (conta_origem != conta_destino) && (valor <= contas[i].saldo)){
            for(int j=0; j < n; j++){
                if(contas[j].num_conta == conta_destino){
                    contas[i].num_conta -= valor;
                    contas[j].num_conta += valor;
                    return;
                }
            }
        }
    }

    printf("Erro na operacao.\n\n");
}

void consulta_saldo(int n, conta_bancaria contas[n], int num_conta){
    for(int i=0; i < n; i++){
        if(num_conta == contas[i].num_conta){
            printf("A conta possui saldo de R$%.2f\n\n", contas[i].saldo);
            return;
        }
    }

    printf("Erro na consulta. ");
}

int main(){
    int n, i, j, num_conta, conta_origem, conta_destino;
    float valor;
    int flag = 1;
    bool unico = true;
    char buffer[100];

    //recebe quantidade de contas
    printf("Digite quantas contas deseja ler: ");
    n = atoi(fgets(buffer, 100, stdin));
    conta_bancaria contas[n];

    //zera os saldos
    for(i=0; i < n; i++){
        contas[i].saldo = 0;
    }

    //leitura dos numeros das contas
    for(i=0; i < n; i++){
        printf("Numero da conta %d: ", i+1);
        contas[i].num_conta = atoi(fgets(buffer, 100, stdin));

        //verifica existencia da conta
        for(j=0; j < i && unico; j++){
            if(contas[i].num_conta == contas[j].num_conta){
                unico = false;
                printf("Numero de conta ja existe. Digite novamente.\n");
                i--;
            }
        }
    }

    //realiza operacoes
    while(flag != 0){
        printf("Escolha a operacao que deseja fazer ou 0 para finalizar: \n1 - Creditar \n2 - Debitar \n3- Transferir \n4 - Consultar saldo\n");
        flag = atoi(fgets(buffer, 100, stdin));

        if (flag == 0) break;

        if(flag == 1){
            //creditar
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser creditado: R$");
            valor = atof(fgets(buffer, 100, stdin));

            creditar(n, contas, num_conta, valor);
        }
        else if(flag == 2){
            //debitar
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser debitado: R$");
            valor = atof(fgets(buffer, 100, stdin));

            debitar(n, contas, num_conta, valor);
        }
        else if(flag == 3){
            //transferir
            printf("Digite a conta de origem: ");
            conta_origem = atoi(fgets(buffer, 100, stdin));
            printf("Digite a conta de destino: ");
            conta_destino = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser transferido: R$");
            valor = atof(fgets(buffer, 100, stdin));

            transferir(n, contas, conta_origem, conta_destino, valor);

        }
        else if(flag == 4){
            //consultar saldo
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));

            consulta_saldo(n, contas, num_conta);
        }
    }

    return 0;
}
