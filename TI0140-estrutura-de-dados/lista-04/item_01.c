#include <stdio.h>

int busca_ternaria(int arr[], int n, int l, int key){

    while(n >= 1){
        int mid1 = l + (n - 1) / 3;
        int mid2 = n - (n - 1) / 3;

        if(arr[mid1] == key){
            return mid1;
        }

        if(arr[mid2] == key){
            return mid2;
        }

        if(key < arr[mid1]){
            n = mid1-1;
        }
        else if(key > arr[mid2]){
            l = mid2 + 1;
        }
        else{
            l = mid1 + 1;
            n = mid2 - 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1,2,18,20,29,30,39,44,55,56,84,96};
    int n = sizeof(arr) / sizeof(int);
    int num = 30;
    int index = 0;

    int res = busca_ternaria(arr, n, index, num);
    
    printf("Index of %d is %d.", num, res);
}