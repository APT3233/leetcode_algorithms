class Solution {
    public int reverse(int x) {
        boolean isNegative = false;

        if(x < 0){
            isNegative = true;
            x = x * -1;
        }

        long tmp = 0;
        while(x != 0){
             int lastNum = x % 10;
            tmp= tmp * 10 + lastNum;
            x = x / 10;
        }
        
        if(isNegative == true){
            tmp = tmp * -1;
        }

        if(tmp > Integer.MAX_VALUE || tmp < Integer.MIN_VALUE){
            return 0;
        }

        return (int)tmp;
    }
}