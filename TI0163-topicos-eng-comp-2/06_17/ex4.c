#include <stdio.h>

// ***************************************************
// O typedef a seguir cria um tipo chamado 'TipoFuncao' que define um
// tipo de dado que é uma função.
// O que determina o tipo, neste caso é:
// - o tipo de retorno da função;
// - os parâmetros usados na função. Leva-se em conta a quantidade,
//     a ordem e o tipo destes parâmetros
typedef int TipoFuncao();

// Cria um vetor de ponteiros para funções do tipo 'TipoFuncao'
TipoFuncao *VetorDeFuncoes[3];

// ***************************************************
// As três funções a seguir são do mesmo tipo de 'TipoFuncao'
// ***************************************************

int Load()
{
    printf("%s\n",     __FUNCTION__);
    return 10;
}

int Print()
{
    printf("%s\n",     __func__);
    return 20;
}
int Quit()
{
    printf("%s\n",     __func__);
    return 30;
}
// ***************************************************
//  Funcao que recebe um ponteiro (PonteiroParaUmaFuncao)
//  para uma função e o 'indice' do 'VetorDeFuncoes'
//  no qual será armazenado o ponteiro
// ***************************************************
void SetCallbackFunc(int indice, TipoFuncao *PonteiroParaUmaFuncao)
{
    VetorDeFuncoes[indice] = PonteiroParaUmaFuncao;
}
// ***************************************************
int main()
{
    int opcao, retorno;

    // Faz cada um dos ponteiros do VetorDeFuncoes apontar para
    // uma função diferente
    SetCallbackFunc(0, Load);
    SetCallbackFunc(1, Print);
    SetCallbackFunc(2, Quit);
   
    do {
        printf("Digite sua opcao(1,2,3) :");
        scanf("%d", &opcao);
        // chama uma função a partir do vetor e obtem o retorno
        retorno = (*VetorDeFuncoes[opcao-1])(); 
        printf ("Retorno da função: %d\n\n", retorno);
    } while(opcao !=3);
}