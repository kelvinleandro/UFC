// 0100 0100 0010 0010 = 16 bits (short)
// 0100 0100 = high (char)
// 0010 0010 = low (char)

#include <stdio.h>

union Data {
    short valor;
    struct {
        char low;
        char high;
    };
};

int main() {
    union Data d;
    
    d.valor = 0x4422;
    
    printf("Valor completo (16 bits): 0x%X\n", d.valor);
    
    printf("High: 0x%X\n", d.high);
    printf("Low: 0x%X\n", d.low);
    
    return 0;
}