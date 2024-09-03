class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int[][] res = new int[m][n];
        int indexes = 0;
        
        if(original.length != m*n) return new int[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = original[indexes];
                indexes++; 
            }
        }
        return res;
    }
}