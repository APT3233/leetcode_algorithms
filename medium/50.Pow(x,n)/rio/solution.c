double myPow(double x, int n) {
    if(n == 0) return 1.0;

    long long N = n;
    if(N < 0){
        x = 1 / x;
        N = N * -1;
    }

    double res = 1.0;
    double current_product = x;

    while(N > 0){
        if( N % 2 == 1){
            res = res * current_product;
        }
        current_product*=current_product;
        N = N / 2;
    }
    return res;
}