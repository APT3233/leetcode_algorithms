

int numberOfMatches(int n){
    int count = 0;
    while(n != 1){
        int tmp = n;
        if(tmp % 2 == 0){
            tmp = tmp / 2;
            count = count + (n - tmp);
            n = tmp;
        }else{
            tmp = (tmp - 1) / 2;
            count = count + (n - tmp);
            n = tmp;
        }
    }
    return count;
}