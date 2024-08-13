class Solution {
    public int lengthOfLastWord(String s) {
       s = s.trim();
       String[] path = s.split(" ");
       
       String lastWord = path[path.length - 1];
       return lastWord.length();
    }
}