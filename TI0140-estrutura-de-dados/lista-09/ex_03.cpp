#include <iostream>

class Registro{
public:
    int chave;
    int dado;
};

class ListaOrdenada{
public:
    Registro** L; // vetor de ponteiros de registros
    int tam_max; // tamanho máximo da lista
    int cont; // número de elementos na lista

    // método construtor, inicializa a lista
    ListaOrdenada(int tamanho){
        tam_max = tamanho;
        L = new Registro*[tam_max]();
        cont = 0;
    }

    // método inserir , retorna a posição do registro inserido no vetor
    int inserir(Registro* reg){
    
    }

    // método buscar , implementa busca binária
    Registro buscar(int chave){
    
    }
    
    // método remover , retira da lista e devolve ponteiro para o registro removido
    Registro remover(int chave){
    
    }
};
