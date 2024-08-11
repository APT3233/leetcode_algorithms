class Solution {
     
    public int removeElement(int[] nums, int val) {
        int v=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]!=val){
             nums[v]=nums[i];
            v++;
            }
        }
        return v;
    }
}