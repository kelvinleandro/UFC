#include <cstdio>
#include <iostream>

using namespace std;

// lista encadeada
class No{
    public:
        int chave;
        No* prox = NULL;
};

// tarefa 1
No* nova_lista_encadeada(int n){
    No* c = new No;
    No* h = c;
    for(int i = 0; i < n; i++){
        h->prox = new No;
        h = h->prox;
    }

    return c;
}

// tarefa 2
void deleta_lista(No* head){
    No* aux = head;
    No* deletado;
    while(aux){
        deletado = aux;
        aux = aux->prox;
        delete deletado;
    }
}

// funcao para retornar tamanho da lista encadeada
int tamanho_lista(No* cabeca){
    if(!cabeca) return 0;
    int cont = 0;
    while(cabeca){
        cabeca = cabeca->prox;
        cont++;
    }
    return cont;
}

// tarefa 3
void imprime_nao_recursivo(No* c){
    int tam = tamanho_lista(c);
    int pilha[tam];
    int ult = -1;
    No* aux = c;

    for(int i = 0; i < tam; i++){
        pilha[++ult] = aux->chave;
        aux = aux->prox;
    }

    for(int i = tam-1; i >= 0; i--){
        cout << pilha[i] << "<-";
    }
}

void imprime_recursivo(No* c){
    if(c == NULL) return;
    imprime_recursivo(c->prox);
    cout << c->chave << " --> ";
}

// tarefa 4
class NoDE{
    public:
        int chave;
        NoDE* prox = NULL;
        NoDE* ante = NULL;
};

class ListaDE{
    public:
        NoDE* cabeca = NULL;
        int cont = 0;

        void inserir(NoDE* no, int pos){
            NoDE* aux = cabeca;
            int chave = no->chave;
            for(int i = 0; i < pos && aux->prox; i++){
                aux = aux->prox;
            }
            aux->prox->ante = no;
            no->ante = aux;
            no->prox = aux->prox;
            aux->prox = no;
            cont++;
        }

        NoDE* remover(int chave){
            NoDE* aux = cabeca;
            while(aux->prox && aux->prox->chave != chave){
                aux = aux->prox;
            }

            NoDE* remover = aux->prox;
            aux->prox = aux->prox->prox;
            aux->prox->ante = aux;
            cont--;
            return remover;
        }
};

// matriz encadeada
class NoMat{
    public:
        int chave;
        NoMat* direita = NULL;
        NoMat* embaixo = NULL;
};

// tarefa 5
NoMat* matriz_linha(int n){
    NoMat* c = new NoMat;
    NoMat* aux = c;
    for(int i = 1; i < n; i++){
        aux->direita = new NoMat;
        aux = aux->direita;
    }

    return c;
}

// tarefa 6
void imprime_matriz(NoMat* c){
    NoMat* aux_linha = c;
    while(aux_linha){
        NoMat* aux_coluna = aux_linha;
        while(aux_coluna){
            cout << aux_coluna->chave << " ";
            aux_coluna = aux_coluna->direita;
        }
        cout << "" << endl;
        aux_linha = aux_linha->embaixo;
    }
}

// tarefa 7
void costura_matriz(NoMat* cima, NoMat* baixo){
    NoMat* aux_cima = cima;
    NoMat* aux_baixo = baixo;

    while(aux_cima->embaixo){
        aux_cima = aux_cima->embaixo;
    }

    while(aux_cima && aux_baixo){
        aux_cima->embaixo = aux_baixo;

        aux_cima = aux_cima->direita;
        aux_baixo = aux_baixo->direita;
    }
}

// tarefa 8
int procura_em_matriz_encadeada(NoMat* c, int row, int col){
    NoMat* aux_linha = c;
    NoMat* aux_coluna = c;

    for(int i = 0; i < row; i++){
        aux_linha = aux_linha->embaixo;
    }

    aux_coluna = aux_linha;
    for(int j = 0; j < col; j++){
        aux_coluna = aux_coluna->direita;
    }
    
    return aux_coluna->chave;
}