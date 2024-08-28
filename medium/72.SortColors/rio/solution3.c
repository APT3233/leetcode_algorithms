
//count_element frequenly -> img

void sortColors(int* nums, int numsSize) {
    int count1 = 0, count2 =  0, count3 = 0;


    for(int i = 0; i < numsSize; i++){
        switch(nums[i]){
            case 0: {
                count1 += 1;
                break;
            }
            case 1: {
                count2 += 1;
                break;
            }
            case 2:{
                count3 += 1;
                break;
            }
        }
    }

    int j = 0;
    for(j; j < count1; j++){
        nums[j] = 0;
    }
    for(j; j < count1+count2; j++){
        nums[j] = 1;
    }
    for(j; j < count1+count2+count3; j++){
        nums[j] = 2;
    }
}