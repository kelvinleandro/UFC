#include <iostream>
#include <climits>

using namespace std;

struct NoDE{ int chave; NoDE *prox, *ant;};

class DequeIntCircular{
public:
    NoDE sent;

    int consultar_esq(){
        return sent.prox->chave;
    }
    
    int consultar_dir(){
        return sent.ant->chave;
    }
    
    DequeIntCircular(){
        sent.prox = sent.ant = &sent;
        sent.chave = INT_MAX;
    }

    ~DequeIntCircular(){
        NoDE* it = sent.prox;
        NoDE* remover;
        while(it != &sent){
            remover = it;
            it = it->prox;
            delete it;
        }
        // delete sent;
    }

    void inserir_dir(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->ant = sent.ant;
        novo->prox = &sent;
        novo->ant->prox = novo;
        sent.ant = novo;
    }
    
    void inserir_esq(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->prox = sent.prox;
        novo->ant = &sent;
        novo->prox->ant = novo;
        sent.prox = novo;
    }

    void remover_esq(){
        if(vazio()) return;
        NoDE* removido = sent.prox;
        sent.prox = sent.prox->prox;
        sent.prox->ant = &sent;
        delete removido;
    }

    void remover_dir(){
        if(vazio()) return;
        NoDE* removido = sent.ant;
        sent.ant = sent.ant->ant;
        sent.ant->prox = &sent;
        delete removido;
    }

    bool vazio(){
        return sent.prox == &sent;
    }

    void imprime(){
        NoDE* it = sent.prox;
        cout << "-------" << endl;
        while(it != &sent){
            cout << it->chave << ", ";
            it = it->prox;
        }
        cout << endl << "-------" << endl;
    }

};

int main(){
    DequeIntCircular deque;
    for(int i = 0; i < 10; i++){
        deque.inserir_dir(i);
    }

    deque.imprime();
}