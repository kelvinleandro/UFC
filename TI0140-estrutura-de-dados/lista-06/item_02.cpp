#include <cstdio>

class Posicao{
    public:
        int l;
        int c;
};

class FilaPosicao{
    public:
        Posicao *v;
        int tam_max;
        int ini;
        int fim;
        int cont;
        // método construtor , inicializa a fila
        FilaPosicao(int tamanho){
            v = new Posicao[tamanho]; // cria vetor de posicoes com o tamanho desejadtam_max = tamanho ;
            ini = 0;
            fim = -1;
            cont = 0;
        }
        // método enfileirar
        void enfileirar(Posicao p){
            if(cont < tam_max){
                fim = (fim+1) % tam_max;
                v[fim] = p;
                cont++;
            }
        }
        // método desenfileirar
        Posicao desenfileirar(){
            Posicao x;
            if(cont>0){
                x = v[ini];
                ini = (ini+1) % tam_max;
                cont--;
            }
            return x;
        }
        // método fila vazia
        int vazia(){
            return cont;
        }
};

int main (){
    FilaPosicao f(10); // cria fila de tamanho 10
    Posicao p;

    for(int i = 0; i < 10; i++){
        p.l = i*i;
        p.c = i*i*i;
        f.enfileirar(p);
    }

    for(int i = 0; i < 5; i ++){
        p = f.desenfileirar();
        printf("linha %d, coluna %d\n", p.l, p.c);
    }
    printf("\n");

    for(int i = 0; i < 5; i++){
        p.l = i*i;
        p.c = i*i*i;
        f.enfileirar(p);
    }

    while(!f.vazia()){
        p = f.desenfileirar();
        printf("linha %d, coluna %d\n", p.l, p.c);
    }
}
