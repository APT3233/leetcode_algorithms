int calSum(int n ){
    int sum = 0;
    while(n != 0){
        sum += pow(n % 10, 2);
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    int result = n;
    while(1){
        result = calSum(result);
        if(result == 1) return true;
        if(result < 1 || result == 89) return false; // 89 ís a unhappy number 
    }

}