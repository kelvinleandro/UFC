#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n, i, j, num_conta, conta_origem, conta_destino;
    float valor;
    int flag = 1;
    bool unico = true, contaexiste = true, deucerto = false;
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
            //creditar
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser creditado: R$");
            valor = atof(fgets(buffer, 100, stdin));
            for(i=0; i < n; i++){
                if(num_conta == num_contas[i]){
                    saldos[i] += valor;
                    break;
                }
                else{
                    printf("Conta nao existe. ");
                }
            }
        }
        else if(flag == 2){
            //debitar
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser debitado: R$");
            valor = atof(fgets(buffer, 100, stdin));

            for(i=0; i < n; i++){
                if((num_conta == num_contas[i]) && (valor <= saldos[i])){
                    saldos[i] -= valor;
                    break;
                }
                else{
                    printf("Erro na operacao. ");
                    break;
                }
            }
        }
        else if(flag == 3){
            //transferir
            printf("Digite a conta de origem: ");
            conta_origem = atoi(fgets(buffer, 100, stdin));
            printf("Digite a conta de destino: ");
            conta_destino = atoi(fgets(buffer, 100, stdin));
            printf("Digite o valor a ser transferido: R$");
            valor = atof(fgets(buffer, 100, stdin));

            for(i=0; i < n; i++){
                if((conta_origem == num_contas[i]) && (conta_origem != conta_destino) && (valor <= saldos[i])){
                    for(j=0; j < n; j++){
                        if(num_contas[j] == conta_destino){
                            saldos[i] -= valor;
                            saldos[j] += valor;
                            deucerto = true;
                            break;
                        }
                    }
                }
            }

        }
        else if(flag == 4){
            //consultar saldo
            printf("Digite o numero da conta: ");
            num_conta = atoi(fgets(buffer, 100, stdin));

            for(i=0; i < n; i++){
                if(num_conta == num_contas[i]){
                    printf("A conta possui saldo de R$%.2f\n\n", saldos[i]);
                    contaexiste = true;
                }
            }

            if(!contaexiste){
                printf("Conta nao existe.\n\n");
            }
        }
    }

    return 0;
}
