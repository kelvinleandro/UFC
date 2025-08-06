#include <stdio.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

void imprimir_struct(Data data) {
    printf("%d/%d/%d\r\n", data.dia, data.mes, data.ano);
}

Data add_data(Data *data, int d, int m, int a) {
    data->dia = d;
    data->mes = m;
    data->ano = a;
}

int main(void) {
    Data hoje = {20, 5, 25};

    imprimir_struct(hoje);
    add_data(&hoje, 21, 4, 24);
    imprimir_struct(hoje);
    // printf("Tam: %lu\r\n", sizeof(hoje));
    return 0;
}