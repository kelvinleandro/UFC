#include <stdio.h>

void imprime_vetor(int v[], int n){
    for(int i = 0; i < n; i ++){
        printf("%d ", v[i]);
    }
}

void calcula_bombas(int minas[], int answer[], int n){
    int quant = 0;
    for(int i = 0; i < n; i++){
        quant = 0;
        if(minas[i] == 1) quant++;

        if(i < n-1){
            if(minas[i+1] == 1) quant++;
        }

        if(i > 0){
            if(minas[i-1] == 1) quant++;
        }

        answer[i] = quant;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int minas[n];
    int resposta[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &minas[i]);
    }

    calcula_bombas(minas, resposta, n);
    imprime_vetor(resposta, n);
    
}