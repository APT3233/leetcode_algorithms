void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j <= i; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for(int i = 0; i < matrixSize; i++){
        reverse(matrix[i], matrixColSize[i]);
    }
}
void reverse(int arr[], int size){
     int l = 0;
    int r = size - 1;
    while(l < r){
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}