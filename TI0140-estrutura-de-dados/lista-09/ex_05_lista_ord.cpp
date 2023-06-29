#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Registro{
public:
    int chave;
    int dado;
};

class ListaOrdenada{};

// realiza n inserções em uma tabela de tamanho m e retorna o tempo decorrrido
// os registros que serão inseridos estão no vetor Regs
int testeInsercao_TDEED(int m, int n, Registro* Regs){
    // cria tabela
    ListaOrdenada TDEED(m);
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

void inicializaChavesAleatorias(int n , Registro* Regs){
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
    Registro* Regs = new Registro[n];
    // inicializa chaves aleatórias
    inicializaChavesAleatorias(n, Regs);
    // testa tabela de dispersão com encadeamento externo e método da divisão
    int duracaoTDEED = testeInsercao_TDEED(m, n, Regs);
    cout << "Duracao do teste de insersao \n" ;
    cout << "Tamanho da tabela: " << m << "\n" ;
    cout << "Numero de registros: " << n << "\n" ;
    cout << "Duracao: " << (float) 1000* duracaoTDEED / CLOCKS_PER_SEC << " ms \n" ;
}