#include <iostream>
using std::cout;
#include "solucao.cpp"

int testar(){
    DicioAVL D; int i; DicioAVL::Noh* nohs[9];
    for(i = 0; i <= 8; ++i){
        DicioAVL::Noh* n = D.inserir(i, i/4);
        if (n == nullptr or n->chave != i or n->valor != i/4) return 1;
        nohs[i] = n;
    }
    
    for(i = 0; i <= 8; ++i){
        if (D.buscar(i) != nohs[i]) return 2;
    }

    if(D.raiz->chave != 3 or D.raiz->esq->valor != 1/4 or
    D.raiz->dir->altura != 3 or D.raiz->esq->esq->esq != &D.sent){
        return 3;
    }

    return 0;
}

int main(){
    if(testar() != 0) cout << "Erro nos testes basicos!\n";
    else cout << "Testes basicos realizados com sucesso.\n";
}