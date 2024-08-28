class Solution {
    public int addDigits(int num) {
          int res = 0;
      if(num < 0){
            return 0;
        }else{
            int temp = num;
            while(temp != 0){
            int temp2 = temp;

            temp2 = temp % 10;
            temp = temp / 10;

            res = temp + temp2;

                if(res < 10){
                    break;
                }else{
                    temp = res;
                }
            }
        }    
        return res;
    }
}