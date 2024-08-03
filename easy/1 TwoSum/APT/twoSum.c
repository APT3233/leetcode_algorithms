#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)a)->value - ((Pair *)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair *pairs = (Pair *)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].index = i;
        pairs[i].value = nums[i];
    }

    qsort(pairs, numsSize, sizeof(Pair), compare);

    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = pairs[left].value + pairs[right].value;
        if (sum == target) {
            int *result = (int *)malloc(2 * sizeof(int));
            result[0] = pairs[left].index;
            result[1] = pairs[right].index;
            *returnSize = 2;
            free(pairs);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    free(pairs);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
