// -----------------------------------------------------------------------------
// Universidade Federal do Ceara, Centro de Ciencias, Departamento de Computacao
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para Implementacao de Dicionario baseado em Arvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICACAO DO(A) ESTUDANTE:
//
// NOME: Kelvin Leandro Martins
// MATRICULA: 540006
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que esta presente na interface abaixo deve ser mantido como esta,
// pois e essa interface que sera utilizada no programa do professor para a
// realizacao dos testes.
//
// A realizacao do trabalho consiste portanto em *completar* a implementacao
// abaixo, tornando-a funcional e atendendo aos requisitos deste trabalho.
// -----------------------------------------------------------------------------

#include <exception>
#include <iostream>
using std::exception;

struct DicioAVL
{
    typedef double TC;  // Tipo das Chaves
    typedef float  TV;  // Tipo dos Valores

    struct Noh{TC chave; TV valor; int altura; Noh *esq, *dir;};

    Noh sent, *raiz;  // "sent": Sentinela.

    // Conforme a declaracao acima, a implementacao deve usar um no sentinela,
    // que representara as subarvores vazias. Assim, por exemplo, os campos
    // "esq" e "dir" das folhas, ao inves de serem ponteiros nulos, apontarao
    // para "sent"; idem para o ponteiro "raiz", quando a arvore estiver vazia.
    // O campo "altura" da sentinela deve sempre valer zero.

    // --------------------------------------------------------------------------

    // Deve criar um dicionario vazio.
    DicioAVL()
    {
        // TODO: Completar aqui.
        sent = {0, 0, 0, nullptr, nullptr};
        raiz = &sent;
    }

    // --------------------------------------------------------------------------

    // Deve desalocar a Arvore AVL.
    ~DicioAVL()
    {
        // TODO: Completar aqui.
        desalocar(raiz);
    }

    // --------------------------------------------------------------------------

    // Deve inserir a chave "c" e o valor "v" no dicionario, partindo da
    // Pre-condicao de que a chave "c" nao existe no dicionario -- ou seja,
    // a funcao nao precisa nem deve fazer esse teste.
    //
    // A funcao deve retornar um ponteiro apontando para o novo no.
    // Em caso de falha de alocacao de memoria, a funcao deve retornar nullptr.
    //
    // ATENCAO: a chave deve permanecer no mesmo no enquanto nao for removida
    // -------  do dicionario. Isso significa que, antes de tal remocao,
    //          deve ser possivel acessar a chave e seu valor a partir do
    //          ponteiro retornado pela funcao de insercao.

    Noh* inserir(TC c, TV v){
        // TODO: Completar aqui.
        try{
            Noh* novo = new Noh{c, v, 1, &sent, &sent};
            insere_recursivo(&raiz, novo);
            return novo;
        }
        catch(exception &e){
            return nullptr;
        }
    }

    // --------------------------------------------------------------------------

    // Deve retornar um ponteiro para o no de chave "c", caso essa chave exista
    // no dicionario; caso a chave nao esteja presente, deve retornar nullptr.

    Noh* buscar(TC c){
        // TODO: Completar aqui.
        Noh* atual = raiz;
        while(atual != &sent){
            if(atual->chave == c){
                return atual;
            }
            else if(c <= atual->chave){
                atual = atual->esq;
            }
            else{
                atual = atual->dir;
            }
        }
        return nullptr;
    }

    void desalocar(Noh* n){
        if(n == &sent) return;
        desalocar(n->esq);
        desalocar(n->dir);
        delete n;
    }

    void insere_recursivo(Noh** n, Noh* novo){
        if(*n == &sent){
            *n = novo;
            return;
        }
        else{
            if(novo->chave < (*n)->chave){
                insere_recursivo(&(*n)->esq, novo);
            }
            else{
                insere_recursivo(&(*n)->dir, novo);
            }
        }

        conserta_avl(n);
    }

    int altura(Noh* n){
        if(n == &sent) return 0;
        int h_esq = altura(n->esq);
        int h_dir = altura(n->dir);
        return std::max(h_esq, h_dir) + 1;
    }

    int b(Noh* n){
        if(n == &sent) return 0;
        return n->dir->altura - n->esq->altura;
    }

    void conserta_avl(Noh** n){
        (*n)->altura = altura(*n);

        if(b(*n) > 1){
            if(b((*n)->dir) < 0){
                rotaciona_dir(&(*n)->dir);
                rotaciona_esq(n);
            }
            else{
                rotaciona_esq(n);
            }
        }
        else if(b(*n) < -1){
            if(b((*n)->esq) < 0){
                rotaciona_dir(n);
            }
            else{
                rotaciona_esq(&(*n)->esq);
                rotaciona_dir(n);
            }
        }

    }

    void rotaciona_dir(Noh** n){
        Noh* x = *n;
        Noh* y = (*n)->esq;
        x->esq = y->dir;
        y->dir = x;
        *n = y;
        x->altura = altura(x);
        y->altura = altura(y);
    }

    void rotaciona_esq(Noh** n){
        Noh* x = *n;
        Noh* y = (*n)->dir;
        x->dir = y->esq;
        y->esq = x;
        *n = y;
        x->altura = altura(x);
        y->altura = altura(y);
    }

}; // DicioAVL  --------------------------------------------------------------