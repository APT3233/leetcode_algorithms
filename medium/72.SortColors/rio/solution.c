//mergesort

void mergeArr(int* inputArr, int* leftHalf, int leftSize, int* rightHalf, int rightSize){
   int i = 0, j = 0, k = 0;
   while(i < leftSize && j < rightSize){
    if(leftHalf[i] <= rightHalf[j]){
        inputArr[k] = leftHalf[i];
        i++;
    }else{
        inputArr[k] = rightHalf[j];
        j++;
    }
     k++;
   }

   while(i < leftSize){
    inputArr[k] = leftHalf[i];
    i++;
    k++;
   }
   while(j <  rightSize){
    inputArr[k] = rightHalf[j];
    j++;
    k++;
   }
}

void sortColors(int* nums, int numsSize) {
   if(numsSize <= 1) return;
   
   int mid = numsSize / 2;

   int leftArr[mid];
   int rightArr[numsSize - mid];

    for(int i = 0; i < mid; i++){
        leftArr[i] = nums[i];
    }

    for(int i = mid; i < numsSize ; i++){
        rightArr[i - mid] = nums[i];
    }

    sortColors(leftArr, mid);
    sortColors(rightArr, numsSize - mid);

    mergeArr(nums, leftArr, mid, rightArr, numsSize - mid);
}

