#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void creditar(int n, int num_contas[n], float saldos[n], int num_conta, float valor){
    for(int i=0; i < n; i++){
        if(num_conta == num_contas[i]){
            saldos[i] += valor;
            return;
        }
    }

    printf("Conta nao existe. ");
}

void debitar(int n, int num_contas[n], float saldos[n], int num_conta, float valor){
    for(int i=0; i < n; i++){
        if((num_conta == num_contas[i]) && (valor <= saldos[i])){
            saldos[i] -= valor;
            return;
        }
    }

    printf("Erro na operacao\n");
}

void transferir(int n, int num_contas[n], float saldos[n], int conta_origem, int conta_destino, float valor){
    for(int i=0; i < n; i++){
        if((conta_origem == num_contas[i]) && (conta_origem != conta_destino) && (valor <= saldos[i])){
            for(int j=0; j < n; j++){
                if(num_contas[j] == conta_destino){
                    saldos[i] -= valor;
                    saldos[j] += valor;
                    return;
                }
            }
        }
    }

    printf("Erro na operacao. ");
}

void consulta_saldo(int n, int num_contas[n], float saldos[n], int num_conta){
    for(int i=0; i < n; i++){
        if(num_conta == num_contas[i]){
            printf("A conta possui saldo de R$%.2f\n\n", saldos[i]);
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
    int num_contas[n];
    float saldos[n];

    //zera os saldos
    for(i=0; i < n; i++){
        saldos[i] = 0;
    }

    //leitura dos numeros das contas
    for(i=0; i < n; i++){
        printf("Numero da conta %d: ", i+1);
        num_contas[i] = atoi(fgets(buffer, 100, stdin));

        //verifica existencia da conta
        for(j=0; j < i && unico; j++){
            if(num_contas[i] == num_contas[j]){
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
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser creditado: R$");
            valor = atof(fgets(buffer, 100, stdin));

            creditar(n, num_contas, saldos, num_conta, valor);
        }
        else if(flag == 2){
            //debitar
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser debitado: R$");
            valor = atof(fgets(buffer, 100, stdin));

            debitar(n, num_contas, saldos, num_conta, valor);
        }
        else if(flag == 3){
            //transferir
            printf("Digite a conta de origem: ");
            conta_origem = atoi(fgets(buffer, 100, stdin));
            printf("Digite a conta de destino: ");
            conta_destino = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser transferido: R$");
            valor = atof(fgets(buffer, 100, stdin));

            transferir(n, num_contas, saldos, conta_origem, conta_destino, valor);

        }
        else if(flag == 4){
            //consultar saldo
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));

            consulta_saldo(n, num_contas, saldos, num_conta);
        }
    }

    return 0;
}
