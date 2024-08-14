class Solution {
    public int lengthOfLongestSubstring(String s) {
       int l = 0;
       int result = 0;
       HashSet<Character> longestSubstring = new HashSet<Character>();
    
        for(int r = 0; r < s.length(); r++){
                while(longestSubstring.contains(s.charAt(r)) == true){
                    longestSubstring.remove(s.charAt(l));
                    l++;
                }
                longestSubstring.add(s.charAt(r));
                result = Math.max(result, r - l + 1);
        }
        return result;
    }
}