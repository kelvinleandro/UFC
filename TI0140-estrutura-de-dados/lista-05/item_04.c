#include <stdio.h>
#include <stdbool.h>

void cocktail_sort(int arr[], int n){
    bool swapped = true;
    int start = 0, end = n-1, aux;
 
    while(swapped){
        swapped = false;
 
        for(int i = start; i < end; i++){
            if(arr[i] > arr[i + 1]){
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                swapped = true;
            }
        }
 
        if(!swapped) break;
 
        swapped = false;
        end--;
 
        for(int i = end - 1; i >= start; i--){
            if(arr[i] > arr[i + 1]){
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                swapped = true;
            }
        }
 
        start++;
    }
}

void imprime_array(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {4, 6, 1, 7, 3, 78, 15, 2, 37, 21, 18};
    int n = sizeof(l) / sizeof(int);

    cocktail_sort(l, n);
    imprime_array(l, n);
}