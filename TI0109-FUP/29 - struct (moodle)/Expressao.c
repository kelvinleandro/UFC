#include <stdio.h>
#include <string.h>

struct expressao{
    int num1, num2;
    char op;
};

int main()
{
    struct expressao test;
    int res;
    
    scanf("%c", &test.op);
    scanf("%d %d", &test.num1, &test.num2);
    
    if(test.op == '+'){
        res = test.num1 + test.num2;
    }
    else if(test.op == '-'){
        res = test.num1 - test.num2;
    }
    else if(test.op == '*'){
        res = test.num1 * test.num2;
    }
    else if(test.op == '/'){
        res = test.num1 / test.num2;
    }

    printf("%d", res);
    return 0;
}
