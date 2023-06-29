#include <iostream>

class NoRegistro{
public:
    int chave;
    NoRegistro* prox;
};

class TabelaDispersao_EE_Divisao {
public:
    NoRegistro** tabela;
    int m; // tamanho da tabela
    int cont; // número de elementos na tabela
    // método construtor , inicializa a tabela
    TabelaDispersao_EE_Divisao(int tamanho){
        m = tamanho;
        tabela = new NoRegistro*[m];
        cont = 0;
    }
    int metodo_divisao(int c){
        return c % m;
    }
    // método inserir
    int inserir( NoRegistro* reg){
        int pos = metodo_divisao(reg->chave);

        if(tabela[pos] == NULL){
            tabela[pos] = reg;
        }
        else{
            reg->prox = tabela[pos];
            tabela[pos] = reg;
        }

        return pos;
    }
    // método buscar
    NoRegistro* buscar(int chave){
        int pos = metodo_divisao(chave);

        if(tabela[pos] == NULL){
            return NULL;
        }
        else{
            NoRegistro* aux = tabela[pos];

            while(aux){
                if(aux->chave == chave){
                    return aux;
                }
                aux = aux->prox;
            }
        }

        return NULL;
    }
    // método remover, devolve um ponteiro para o nó removido
    // não libera o espaço do nó
    NoRegistro* remover (int chave){
        int pos = metodo_divisao(chave);

        if(tabela[pos] == NULL){
            return NULL;
        }
        else{
            NoRegistro* aux = tabela[pos];

            while(aux->prox){
                if(aux->prox->chave == chave){
                    NoRegistro* removido = aux->prox;
                    aux->prox = aux->prox->prox;
                    return removido;
                }

                aux = aux->prox;
            }
        }
    }
    // método eliminar, remove o nó liberando o espaço
    void eliminar(int chave){
        int pos = metodo_divisao(chave);

        if(tabela[pos] != NULL){
            NoRegistro* aux;
            if(tabela[pos]->chave == chave){
                aux = tabela[pos];
                tabela[pos] = tabela[pos]->prox;
                delete aux;
            }
            else{
                aux = tabela[pos];

                while(aux->prox){
                    if(aux->prox->chave == chave){
                        NoRegistro* removido = aux->prox;
                        aux->prox = aux->prox->prox;
                        delete removido;
                        break;
                    }

                    aux = aux->prox;
                }
            }
        }
    }
};