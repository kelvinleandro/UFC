#include <stdio.h>
#include <stdbool.h>

struct iterable{
    int *pointer;
    int *end;
};


bool is_exhausted(struct iterable it){return it.pointer == it.end;}
int current_value(struct iterable it){return *(it.pointer);}

bool some_exhausted(int n, struct iterable* it){
    for(int i = 0; i < n; i++){
        if(is_exhausted(it[i])){
            return true;
        }
    }

    return false;
}

void remove_first_exhausted(int *n, struct iterable *it){
    int aux;
    for(int i = 0; i < *n; i++){
        if(is_exhausted(it[i])){
            aux = it[i];
            it[i] = it[*n-1];
            *n = *n -1;
            return;
        }
    }
}

int get_min_and_advance(int n, struct iterable* it){
    struct iterable* min = &it[0];
    for(int i = 1; i < n; i++){
        int current_min = current_value(*min);
        int possible_min = current_value(it[i]);
        if(possible_min < current_min) min = &it[i];
    }
    int min_value = current_value(*min);
    min->pointer++;
    return min_value;
}

void merge_n_recursively(int inserted, int *M, int n, struct iterable* it){
    if(n > 0){
        while(!some_exhauted(n, it)){
            M[inserted++] = get_min_and_advance(n, it);
        }
    }

    if(n > 0){
        remove_first_exhausted(&n, it);
        merge_n_recursively(inserted, M, n, it);
    }
}

int* merge_three(int n, int* L){
    int* M[n];

    struct iterable it[3] = {
        {L, L+ n/3},
        {L + n/3, L + 2*n/3},
        {L + 2*n/3, L + n}
    };

    merge_n_recursively(0,M,3,it);
    return M;
}

int main(){
    int L[] = {1,2,18,20,4,17,96,18,77,84,85};
    int *M = merge_three(12, L);

    for(int i = 0; i < 12; i++){
        printf("%d ", M[i]);
    }
}