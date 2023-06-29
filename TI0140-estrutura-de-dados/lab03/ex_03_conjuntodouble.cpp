#include <iostream>

using namespace std;

struct No{ double chave; No* prox; };

class ConjuntoDoubleSentinela{

    No* localiza(int e){
        No* it = sent;
        sent->chave = e;
        while(it->prox->chave != e){
            it = it->prox;
        }
        return it;
    }

public:
    No* sent;
    
    ConjuntoDoubleSentinela(){
        sent = new No{0, nullptr};
        sent->prox = sent;
    }
    
    bool pertence(double e){
        return localiza(e)->prox != sent;
    }
    
    void inserir_sem_testar(double e){
        No* novo = new No{e, sent};
        novo->prox = sent->prox;
        sent->prox = novo;
    }
    
    void inserir(double e){
        if(!pertence(e)){
            inserir_sem_testar(e);
        }
    }
    
    void remover(double e){
        No* remover = localiza(e);
        if(remover->prox != sent){
            No* removido = remover->prox;
            remover->prox = remover->prox->prox;
            delete removido;
        }
    }
    
    ~ConjuntoDoubleSentinela(){
        No* it = sent->prox, *remover;
        while(it != sent){
            remover = it;
            it = it->prox;
            delete remover;
        }
        delete sent;
    }
    
    void imprime(){
        cout << "------" << endl;
        No* it = sent;
        while(it->prox != sent){
            cout << it->prox->chave << ", ";
            it = it->prox;
        }
        cout << endl << "------" << endl;
    }
    
};