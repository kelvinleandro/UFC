#include <stdio.h>
#include "utils.h"
#include "math/calc.h"


int main() {
    printf("Hello from main!\n");
    utils_func();
    printf("2 + 3 = %d\n", add(2, 3));
    return 0;
}
