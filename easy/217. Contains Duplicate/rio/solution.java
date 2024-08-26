class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> elementCounting = new HashMap<>();


        for(Integer e : nums){
            if(elementCounting.containsKey(e)) {
               return true;
            }else{
                elementCounting.put(e, 1);
            }
        }
        return false;
    }
}