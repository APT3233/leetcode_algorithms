class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
         List<List<Integer>> result =  new ArrayList<>();
         Arrays.sort(nums);

         int n = nums.length;
       
        for(int i =0; i < n; i++){
            if(i != 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if( sum  <  0){
                    l+=1;
                }else if(sum > 0){
                    r-=1;
                }else{
                    List<Integer> element = Arrays.asList(nums[i], nums[l], nums[r]);
                    result.add(element);

                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l-1]) l++;
                }
            }
           
         } 
        return result;
    }
}