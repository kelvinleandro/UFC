#include <stdio.h>

typedef union {
    short a;
    char b;
} Mutante;

int main(void) {
    Mutante mt;
    printf("sizeof(mt) = %ld\n", sizeof(mt));
    return 0;
}