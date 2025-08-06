// gcc -DSTM main.c -o main.o
#include <stdio.h>
#include "defines.h"

int main() {
    int reg = 0;

#ifdef STM
    reg = 0x123;
    printf("STM32 reg = 0x%x\n", reg);
#elif CC
    reg = 0x256;
    printf("CC1312 reg = 0x%x\n", reg);
#else
    printf("REG comum = 0x%x\n", reg);
#endif
    return 0;
}
