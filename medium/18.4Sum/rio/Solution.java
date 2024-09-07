class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(nums);
        int n = nums.length;

        for(int i  = 0; i < n; i++){

            if(nums[i] >= Integer.MAX_VALUE) return result;

            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i +1; j < n - 2; j++){
                if(nums[j] == nums[j - 1] && j > i + 1) continue;

                int l = j + 1;
                int r = n - 1;

                while(l < r){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    if(sum < target){
                        l++;
                    }else if(sum > target){
                        r--;
                    }else{
                        List<Integer> el = Arrays.asList(nums[i], nums[j], nums[l], nums[r]);
                           if(result.contains(el) == true){
                            break;
                           }else{
                             result.add(el);
                           }
                            l++;
                        r--;
                   

                        while( l < r && nums[l] == nums[l-1]) l++;
                    }
                }
            }
        }
        return new ArrayList<>(result);
    }
}