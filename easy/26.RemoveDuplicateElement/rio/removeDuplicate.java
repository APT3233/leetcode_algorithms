class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int k = 1;
        int i = 1;
        while(i < nums.length){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
}
