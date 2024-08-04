bool isPalindrome(int x){
    if(x < 0) return false;
    int n = x;
    double temp = 0;
    while(n != 0){
        temp = temp * 10 + n % 10; 
        n = n / 10;
    }
   return x == temp;
}