#include <cstdio>
#include <iostream>

using namespace std;

class DequeInt{
    struct Noh{int elem; Noh *ant, *prox;};
    Noh *esq, *dir;
 
    public:
    int consultar_dir(){
        return dir->elem;
    }
    
    int consultar_esq(){
        return esq->elem;
    }
    
    DequeInt(){
        esq = dir = nullptr;
    }
    
    ~DequeInt(){
        while(esq != nullptr){
            Noh* remover = esq;
            esq = esq->prox;
            delete remover;
        }
    }
    void inserir_dir(int e){
        Noh* n = new Noh;
        n->elem = e;
        
        if(dir == nullptr){
            esq = dir = n;
            n->ant = n->prox = nullptr;
        }
        else{
            dir->prox = n;
            n->ant = dir;
            dir = n;
            n->prox = nullptr;
        }
    }

    void inserir_esq(int e){
        Noh* n = new Noh;
        n->elem = e;
        
        if(esq == nullptr){
            esq = dir = n;
            n->ant = n->prox = nullptr;
        }
        else{
            esq->ant = n;
            n->prox = esq;
            esq = n;
            n->ant = nullptr;
        }
    }
    void remover_dir(){
        Noh* aux = dir;
        dir = dir->ant;
        dir->prox = nullptr;
        delete aux;
    }

    void remover_esq(){
        Noh* aux = esq;
        esq = esq->prox;
        esq->ant = nullptr;
        delete aux;
    }
    
    bool vazio(){
        return esq == nullptr && dir == nullptr;
    }
};

int main(){
    DequeInt deque;
    deque.inserir_dir(3);
    deque.inserir_dir(2);
    deque.inserir_esq(5);
    deque.inserir_esq(1);
    deque.inserir_esq(2);
    deque.remover_dir();
    deque.remover_esq();

    cout << deque.consultar_esq() << endl;
    cout << deque.consultar_dir() << endl;
}