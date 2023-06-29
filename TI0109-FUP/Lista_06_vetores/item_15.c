#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Digite um valor para n: ");
    scanf("%d", &n);
    float conj[n], soma = 0, media, variancia, varian_soma = 0, desv_padrao;
    
    for (int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%f", &conj[i]);
    }

    for (int i = 0; i < n; i++){
        soma += conj[i];
    }
    media = soma / n;

    for (int i = 0; i < n; i++){
        varian_soma += pow((conj[i] - media), 2);
    }
    variancia = varian_soma /n;
    desv_padrao = sqrt(variancia);

    printf("Media = %.1f\n", media);
    printf("Variancia = %.1f\n", variancia);
    printf("Desvio padrao = %.1f", desv_padrao);

}