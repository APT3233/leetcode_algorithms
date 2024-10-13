
class Solution {

    public String longestPalindrome(String s) {
        int size = s.length();
        if (size == 0) {
            return "";
        }

        int[][] F = new int[size][size];
        int maxLength = 1;
        int startIndex = 0;
       
        for (int i = 0; i < size; i++) {
            F[i][i] = 1; // All single characters are palindromes
        }


        for (int i = 0; i < size - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                F[i][i + 1] = 1;
                startIndex = i;
              
                maxLength = 2;
            }
        }

        for(int len = 3; len <= size; len++){
            for(int i = 0; i <= size - len; i++){
                int j = i + len -1;
                if((s.charAt(i) ==s.charAt(j)) && (F[i+1][j-1] == 1)){
                    F[i][j] = 1;
                    startIndex = i;
                    maxLength = len;
                }
            }
        }
        System.out.println("done");

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size; j++){
                System.out.print(" "+F[i][j]+" ");
                if(j == size -1){
                    System.out.println("");
                }
            }
        }

        return s.substring(startIndex, startIndex + maxLength);
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        String res = s.longestPalindrome("babad");
        System.out.println(res);
    }
}
