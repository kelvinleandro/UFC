#include <cstdio>
#include <iostream>

using namespace std;

struct Noh{
    double elem; 
    Noh *prox;
};

class ConjuntoDouble{
    Noh* head;

    Noh* localizar(double e){
        Noh* aux = head;
        while(aux->prox->elem != e){
            aux = aux->prox;
        }
        return aux;
    }

    public:
    // Cria um conjunto vazio representado atraves de lista encadeada.
    ConjuntoDouble(){
        head = nullptr;
    }
    
    // Retorna "true" se e somente se "e" pertence ao conjunto.
    bool pertence(double e){
        Noh* aux = head;
        while(aux && aux->elem != e){
            aux = aux->prox;
        }
        return aux->elem == e;
    }

    // Insere "e" no conjunto sem testar se "e" esta no conjunto.
    void inserir_sem_testar(double e){
        Noh* no = new Noh;
        no->elem = e;
        no->prox = head;
        head = no;
    }

    // Insere "e" no conjunto apenas se "e" ainda nao pertence ao conjunto.
    void inserir(double e){
        if(!pertence(e)){
            inserir_sem_testar(e);
        }
    }

    // Remove "e" do conjunto, caso "e" pertenca a ele;
    // se "e" nao pertence ao conjunto, mantem-no inalterado.
    void remover(double e){
        Noh* aux = head;
        if(head->elem == e){
            head = head->prox;
            delete aux;
        }
        else{
            while(aux && aux->prox->elem != e){
                aux = aux->prox;
            }
            Noh* remover = aux->prox;
            aux->prox = aux->prox->prox;
            delete remover;
        }
    }

    void imprimir(){
        Noh* aux = head;
        while(aux != nullptr){
            cout << aux->elem << " ";
            aux = aux->prox;
        }
    }

    // Desaloca a lista encadeada.
    ~ConjuntoDouble(){
        Noh* aux= head;
        while(aux){
            Noh* remover = aux;
            aux = aux->prox;
            delete remover;
        }
    }
};

int main(){
    ConjuntoDouble conj;
    conj.inserir_sem_testar(3);
    conj.inserir(3);
    conj.inserir_sem_testar(4);
    conj.inserir_sem_testar(2);
    conj.inserir_sem_testar(7);
    conj.inserir_sem_testar(8);
    conj.inserir(2);
    conj.remover(4);

    conj.imprimir();
}