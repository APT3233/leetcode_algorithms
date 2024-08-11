import java.util.ArrayList;


class Solution {
    public int strStr(String haystack, String needle) {
         int startPoint = -1;
         if (needle.isEmpty() || haystack.isEmpty()) {
             return startPoint;
         }
         if (haystack.length() < needle.length()) {
             return startPoint;
         }
 
         ArrayList<Integer> posList = findPos(haystack, needle);
 
         for (int i = 0; i < posList.size(); i++) {
             startPoint = posList.get(i);
 
             int index = 0;
             for (int j = startPoint; j < startPoint + needle.length(); j++) {
                 if (j >= haystack.length() || haystack.charAt(j) != needle.charAt(index)) {
                     startPoint = -1;
                     break;
                 }
                 index++;
             }
             if (startPoint != -1) {
                 break;
             }
         }
         return startPoint;
     }
 
     public ArrayList<Integer> findPos(String haystack, String needle) {
         ArrayList<Integer> pos = new ArrayList<>();
         int i = 0;
         while (i <= haystack.length() - needle.length()) {
             if (haystack.charAt(i) == needle.charAt(0)) {
                 pos.add(i);
             }
             i++;
         }
         return pos;
     }
 }