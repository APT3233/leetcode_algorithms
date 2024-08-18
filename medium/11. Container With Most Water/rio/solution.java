class Solution {
    public String intToRoman(int num) {
        int[] intCode = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] Roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V","IV","I"};
    
        StringBuilder result = new StringBuilder();
        for(int i = 0; i < intCode.length; i++){
            while(num >= intCode[i]){
                result.append(Roman[i]);
                num = num - intCode[i];
            }
        }
        return result.toString();
    }
}