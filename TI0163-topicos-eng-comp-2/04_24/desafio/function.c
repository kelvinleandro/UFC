int deti(int a, int b) {
    int total = 1;
    
    for (int i = 0; i < 2*b; i++) {
        total *= a;
    }

    return total / 3;
}