#include <stdio.h>
#include <math.h>
int main(){
    int i, n, d, quant_digits = 0, result = 0;

    // recebe digito com problema, onde 1 <= n <= 9
    printf("Digite o digito com problema: ");
    scanf("%d", &d);

    // recebe valor inicial (com o digito com problema)
    printf("Digite o numero originalmente negociado: ");
    scanf("%d", &n);

    // conta a quantidade de digitos do valor e armazena em uma variavel
    quant_digits = floor(log10(n)) + 1;
    int decomposto[quant_digits];

    for (i = quant_digits-1; i >=0; i--){
        decomposto[i] = n%10;
        n /= 10;
    }

    for(i=0; i< quant_digits; i++){
        if(decomposto[i] != d){
            result = result*10 + decomposto[i];
        }
    }

    printf("Numero sem o digito com problema: %d", result);
    return 0;
}
