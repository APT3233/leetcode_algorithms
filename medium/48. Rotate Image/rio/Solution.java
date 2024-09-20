class Solution {
    public void rotate(int[][] matrix) {
        int row = matrix.length;
        for(int i = 0; i < row; i++){
            for(int j = 0; j<=i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
         for (int i = 0; i < row; i++) {
            reverseArray(matrix[i]);
        }

    }
    public void reverseArray(int arr[]){
       int l = 0, r = arr.length - 1;
      while(l < r){
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        } 
    }
    

}