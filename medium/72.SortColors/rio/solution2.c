//bubbleSort

void sortColors(int* nums, int numsSize) {
    int temp = 0;
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] > nums[j]){
               temp = nums[i];
               nums[i] = nums[j];
               nums[j] = temp; 
            }
        }
    }
}