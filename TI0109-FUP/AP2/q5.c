#include <stdio.h>

int main(){
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);
    int xi[c], xy[m];
    for(int i = 0; i < c; i++){
        scanf("%d", &xi[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &xy[i]);
    }

    int res = c;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < c; j++){
            if(xy[i] == xi[j]){
                res--;
            }
        }
    }

    printf("%d", res);
}