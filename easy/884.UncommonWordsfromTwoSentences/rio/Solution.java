
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        HashMap<String, Integer> myMap = new HashMap<>();

        String[] arrS1 =  s1.split(" ");
        String[] arrS2 = s2.split(" ");
    

        for(String str : arrS1){
            myMap.put(str, myMap.getOrDefault(str, 0) + 1);
        }
        for(String str : arrS2){
            myMap.put(str, myMap.getOrDefault(str, 0) + 1);
        }


        ArrayList<String> res = new ArrayList<>();
        for(String str : myMap.keySet()){
            if(myMap.get(str) == 1){
                res.add(str);
            }
        }
        return res.toArray(new String[res.size()]);
    }
}