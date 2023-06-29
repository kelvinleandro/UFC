#include <stdio.h>

int main(){
    int numero1, numero2, numero3, num_conta, conta_origem, conta_destino;
    float saldo1 = 0, saldo2 = 0, saldo3 = 0, valor;
    int flag = 1;

    //recebe numeros das contas
    printf("Digite o numero da conta 1: ");
    scanf("%d", &numero1);
    printf("Digite o numero da conta 2: ");
    scanf("%d", &numero2);
    printf("Digite o numero da conta 3: ");
    scanf("%d", &numero3);

    //realiza operacoes
    while(flag != 0){
        printf("Escolha a operacao que deseja fazer ou 0 para finalizar: \n1 - Creditar \n2 - Debitar \n3- Transferir \n4 - Consultar saldo\n");
        scanf("%d", &flag);

        if (flag == 0) break;

        if(flag == 1){
            //creditar
            //do{
                printf("Digite o numero da conta: ");
                scanf("%d", &num_conta);
                printf("Digite o valor a ser creditado: R$");
                scanf("%f", &valor);
                if(num_conta == numero1){
                    saldo1 += valor;
                }
                else if(num_conta == numero2){
                    saldo2 += valor;
                }
                else if(num_conta == numero3){
                    saldo3 += valor;
                }
                else{
                    printf("Conta nao existe. ");
                }
            //}while((num_conta != numero1) || (num_conta != numero2) || (num_conta != numero3));
        }
        else if(flag == 2){
            //debitar
            printf("Digite o numero da conta: ");
            scanf("%d", &num_conta);
            printf("Digite o valor a ser debitado: R$");
            scanf("%f", &valor);
            if((num_conta == numero1) && (valor <= saldo1)){
                saldo1 -= valor;
            }
            else if((num_conta == numero2) && (valor <= saldo2)){
                saldo2 -= valor;
            }
            else if((num_conta == numero3) && (valor <= saldo3)){
                saldo3 -= valor;
            }
            else{
                printf("Conta nao existe. ");
            }
        }
        else if(flag == 3){
            //transferir
            printf("Digite a conta de origem: ");
            scanf("%d", &conta_origem);
            printf("Digite a conta de destino: ");
            scanf("%d", &conta_destino);
            printf("Digite o valor a ser transferido: R$");
            scanf("%f", &valor);

            if((conta_origem == numero1) && (conta_origem != conta_destino) && (valor <= saldo1)){
                if(conta_destino == numero2){
                    saldo1 -= valor;
                    saldo2 += valor;
                }
                else if(conta_destino == numero3){
                    saldo1 -= valor;
                    saldo3 += valor;
                }
                else{
                    printf("Operacao invalida.\n");
                }
            }
            else if((conta_origem == numero2) && (conta_origem != conta_destino) && (valor <= saldo2)){
                if(conta_destino == numero1){
                    saldo2 -= valor;
                    saldo1 += valor;
                }
                else if(conta_destino == numero3){
                    saldo2 -= valor;
                    saldo3 += valor;
                }
                else{
                    printf("Operacao invalida.\n");
                }
            }
            else if((conta_origem == numero3) && (conta_origem != conta_destino) && (valor <= saldo3)){
                if(conta_destino == numero1){
                    saldo3 -= valor;
                    saldo1 += valor;
                }
                else if(conta_destino == numero2){
                    saldo3 -= valor;
                    saldo2 += valor;
                }
                else{
                    printf("Operacao invalida.\n");
                }
            }
            else{
                printf("Ocorreu erro na operacao.\n");
            }

        }
        else if(flag == 4){
            //consultar saldo
            printf("Digite o numero da conta: ");
            scanf("%d", &num_conta);

            if(num_conta == numero1){
                printf("Conta %d possui saldo de R$%.2f\n\n", numero1, saldo1);
            }
            else if(num_conta == numero2){
                printf("Conta %d possui saldo de R$%.2f\n\n", numero2, saldo2);
            }
            else if(num_conta == numero3){
                printf("Conta %d possui saldo de R$%.2f\n\n", numero3, saldo3);
            }
            else{
                printf("Conta nao existe.");
            }
        }
        else{
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}