#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

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

// realiza n inserções em uma tabela de tamanho m e retorna o tempo decorrrido
// os registros que serão inseridos estão no vetor Regs
int testeInsercao_TDEED(int m, int n, NoRegistro* Regs){
    // cria tabela
    TabelaDispersao_EE_Divisao TDEED(m);
    // registra inicio das inserções
    int inicio, fim;
    // registra início do procedimento de inserção
    inicio = clock();
    // insere os nós na tabela
    for(int i = 0; i < n; i++){
        TDEED.inserir(&Regs[i]);
    }
    // registra o final das inserções
    fim = clock();
    return fim - inicio;
}

void inicializaChavesAleatorias(int n , NoRegistro* Regs){
    // inicializa os registros com chaves aleatórias não repetidas
    srand(time(0));
    for(int i = 0; i < n; i++){
        Regs[i].chave = rand();
    }
}

int main(){
    int n = 10000; // número de registros a serem inseridos
    int m = 5000; // tamanho da tabela de dispersão
    // cria registros a serem inseridos nas respectivas estruturas
    NoRegistro* Regs = new NoRegistro[n];
    // inicializa chaves aleatórias
    inicializaChavesAleatorias(n, Regs);
    // testa tabela de dispersão com encadeamento externo e método da divisão
    int duracaoTDEED = testeInsercao_TDEED(m, n, Regs);
    cout << "Duracao do teste de insersao \n" ;
    cout << "Tamanho da tabela: " << m << "\n" ;
    cout << "Numero de registros: " << n << "\n" ;
    cout << "Duracao: " << (float) 1000* duracaoTDEED / CLOCKS_PER_SEC << " ms \n" ;
}