#include <iostream>
#include <stdexcept>
using namespace std;

#define PAI(i) (i-1)/2
#define ESQ(i) 2*i + 1
#define DIR(i) 2*i + 2

class Monte{
    int tam_max;
    int quant;
    double *v;
    bool desaloca;

    void heapify(double *v, int i){
        int maior = i;
        if(ESQ(i) < tam_max and v[ESQ(i)] > v[i]){
            maior = ESQ(i);
        }

        if(DIR(i) < tam_max and v[DIR(i)] > v[maior]){
            maior = DIR(i);
        }
        
        if(maior != i){
            swap(v[i], v[maior]);
            heapify(v, maior);
        }
    }

    void buildMaxHeap(double *v, int n){
        for(int i = (n-1)/2; i >= 0; i--){
            heapify(v, i);
        }
    }

public:
    Monte (int tam){ 
        tam_max = tam;
        quant = 0;
        v = new double[tam];
        desaloca = true;
    }

    Monte (double *vetor, int tam_vetor){ 
        tam_max = quant = tam_vetor;
        v = vetor;
        desaloca = false;
        buildMaxHeap(v, quant);
    }

    ~Monte(){ 
        if(desaloca) delete []v;
    }

    int capacidade(){ 
        return tam_max;
    }

    int num_elementos(){ 
        return quant;
    }

    void inserir(double elem){
        if(num_elementos() == tam_max)
            throw runtime_error("Tentativa de insercao com monte cheio!");

        int pos = quant;
        v[pos] = elem;
        quant++;

        for(int i = pos; i != 0 && v[i] > v[PAI(i)]; i = PAI(i)){
            swap(v[i] , v[PAI(i)]);
        }
    }

    double consultar(){
        if(num_elementos() == 0)
            throw runtime_error("Tentativa de consulta com monte vazio!");

        return v[0];
    }

    void remover(){
        if(num_elementos() == 0)
            throw runtime_error("Tentativa de remocao com monte vazio!");

        swap(v[0], v[quant-1]);
        quant--;
        int i = 0;

        while(i < quant){
            int maior;
            if(ESQ(i) >= quant) break;

            if(DIR(i) < quant && v[DIR(i)] > v[ESQ(i)]){
                maior = DIR(i);
            }
            else if(ESQ(i) < quant){
                maior = ESQ(i);
            }

            if(v[i] < v[maior]){
                swap(v[i], v[maior]);
                i = maior;
            }
            else break;
        }
    }

    void esvaziar_ordenando(){
        while(quant > 0){
            remover();
        }
    }

};

int main(){
    double v[10] = { 0, 4, 9, 6, 1, 2, 5, 8, 7, 3 };

    // Monte M(10);
    Monte M(v, 10); 
    M.esvaziar_ordenando();

    if (M.capacidade() != 10 or M.num_elementos() != 0) return 1;
    // for (int i = 0; i < 10; ++i) M.inserir(i);
    // cout << "Maximo: " << M.consultar() << '\n';
    // M.imprimir();
    // while (M.num_elementos() != 0){
    //     cout << "Remocao de " << M.consultar() << '\n';
    //     M.remover();
    // }

    for (int i = 0; i < 10; ++i) cout << ' ' << v[i];
    cout << '\n';
}