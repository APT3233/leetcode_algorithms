#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
     *returnSize = 0 ;
    for(int i = 0; i < numsSize; i++){
        int remain = target - nums[i];
        for(int k  = i + 1; k < numsSize; k++){
            if(nums[k] == remain){
              result[0] = i;
              result[1] = k;
              *returnSize = 2;
              return result;
            }
        }
    }
    return NULL;
}