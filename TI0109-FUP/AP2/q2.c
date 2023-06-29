#include <stdio.h>

void calculameses(double c, double acumulo){
    double total = c;
    int meses = 1;
    while(total <= acumulo){
        total = c + (total * 1.004);
        meses = meses + 1;
    }

    printf("%d", meses);
}

int main(){
    double s, c, acumulo = 0;
    scanf("%lf %lf", &s, &c);
    acumulo = s/0.004;
    printf("%.2lf\n", acumulo);
    calculameses(c, acumulo);
}