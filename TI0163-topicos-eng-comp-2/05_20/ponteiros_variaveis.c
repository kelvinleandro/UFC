#include <stdio.h>

void imprimir_vetor(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
}

void modificar_vetor(float *arr, int pos, float valor) {
    arr[pos] = valor;
}

int main(void) {
    float v[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int i;
    float *p;
    int n = sizeof(v) / sizeof(v[0]);

    imprimir_vetor(v, n);
    printf("\n");

    for (i = 0; i < 7; i++) printf("%.1f ", *(v + i));
    printf("\n");

    for (i = 0, p = v; i < 7; i++, p++) {
        printf("%.1f ", *p);
    }
    printf("\n");

    modificar_vetor(v, 0, 11.0);
    imprimir_vetor(v, n);
    printf("\n");

    return 0;
}