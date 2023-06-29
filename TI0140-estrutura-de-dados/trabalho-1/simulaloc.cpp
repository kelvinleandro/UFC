#include <cstdio>
#include <exception>
#include <iostream>

using namespace std;
using std::exception;

struct SimulAloc{
    struct Noh{int ini, tam; Noh *prox;};
    Noh* prim;

    bool inicializar(int ini, int tam){
        try{
            prim = new Noh{ini,tam,nullptr};
            return false;
        }
        catch(exception& e){
            return true;
        }
    }

    int alocar(int tam){
        if(prim && tam != 0){
            int num;
            if(tam <= prim->tam){
                num = prim->ini + prim->tam - tam;
                prim->tam -= tam;

                if(prim->tam == 0){
                    Noh *remover = prim;
                    prim = prim->prox;
                    delete remover;
                }
                return num;
            }
            else{
                Noh *atual = prim;
                while(atual->prox && tam > atual->prox->tam){
                    atual = atual->prox;
                }

                if(atual->prox){
                    num = atual->prox->ini + atual->prox->tam - tam;
                    atual->prox->tam -= tam;
                    if(atual->prox->tam == 0){
                        Noh *remover = atual->prox;
                        atual->prox = atual->prox->prox;
                        delete remover;
                    }
                    return num;
                }
            }
        }
        return -1;
    }

    bool desalocar(int ini, int tam){
        if(prim == nullptr){
            prim = new Noh{ini, tam, nullptr};
            return false;
        }
        Noh *aux, *atual;

        if(prim->ini > ini+tam){
            aux = new Noh{ini,tam,prim};
            prim = aux;
            return false;
        }
        
        if(prim->ini == ini+tam){
            prim->ini = ini;
            prim->tam += tam;
            return false;
        }

        for(atual = prim; atual->prox != nullptr; atual = atual->prox){
            if(atual->ini + atual->tam == ini && atual->prox->ini == ini+tam){
                aux = atual->prox;
                atual->tam += tam + aux->tam;
                atual->prox = aux->prox;
                delete aux;
                return false;
            }
            else if(atual->ini + atual->tam == ini && atual->prox->ini > ini+tam){
                atual->tam += tam;
                return false;
            }
            else if(atual->ini + atual->tam < ini && atual->prox->ini == ini+tam){
                atual->prox->ini = ini;
                atual->prox->tam += tam;
                return false;
            }
            else if(atual->ini + atual->tam < ini && atual->prox->ini > ini+tam){
                aux = new Noh{ini, tam, atual->prox};
                atual->prox = aux;
                return false;
            }
        }

        if(atual->ini + atual->tam == ini){
            atual->tam += tam;
            return false;
        }
        else if(atual->ini + atual->tam < ini){
            atual->prox = new Noh{ini, tam, nullptr};
            return false;
        }

        return true;
    }

    void terminar(){
        Noh *remover;
        while(prim){
            remover = prim;
            prim = prim->prox;
            delete remover;
        }
    }
};