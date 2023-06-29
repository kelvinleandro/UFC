#include <stdio.h>

typedef struct{
     int dia;
     int mes;
     int ano;
}Data;

typedef enum { LT, EQ, GT} compare;

compare compararDatas(Data dt1, Data dt2){
    compare res = GT;
    if(dt1.ano < dt2.ano){
        res = LT;
    }
    else if(dt1.ano == dt2.ano){
        if(dt1.mes < dt2.mes){
            res = LT;
        }
        else if(dt1.mes > dt2.mes){
            res = GT;
        }
        else if(dt2.mes == dt2.mes){
            if(dt1.dia < dt2.dia){
                res = LT;
            }
            else if(dt1.dia == dt2.dia){
                res = EQ;
            }
        }
    }

    return res;
}


int main(){
    Data d1, d2;
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);
    compare res;
    res = compararDatas(d1,d2);

    if(res == LT){
        printf("Mais antiga\n");
    }
    else if(res == EQ){
        printf("Iguais\n");
    }
    else if(res == GT){
        printf("Mais recente\n");
    }
}