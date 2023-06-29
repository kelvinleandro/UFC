#include <cstdio>

class FilaInt{
    public:
        int *v;
        int tam_max;
        int ini;
        int fim;
        int cont;
        // método construtor, inicializa a fila
        FilaInt(int tamanho){
            v = new int[tamanho]; // cria vetor de inteiros com o tamanho desejado
            tam_max = tamanho;
            ini = 0;
            fim = -1;
            cont = 0;
        }
        // método enfileirar
        void enfileirar(int x){
            if(cont < tam_max){
                fim++;
                v[fim] = x;
                cont++;
            }
        }
        // método desenfileirar
        int desenfileirar(){
            int x;
            if(cont>0){
                x = v[ini];
                ini++;
                cont--;
            }
            return x;
        }
        // método fila vazia
        int vazia(){
            return cont;
        }
};

int main(){
    FilaInt f(10); // cria fila de tamanho 10
    for(int i = 0; i < 10; i++){
        f.enfileirar(i);
    }
    for(int i = 0; i < 5; i++){
        printf("%d , ", f.desenfileirar());
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        f.enfileirar(i);
    }
    while(!f.vazia()){
        printf("%d, ", f.desenfileirar());
    }
}