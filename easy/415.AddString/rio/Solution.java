import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String addStrings(String num1, String num2) {
        List<Integer> res = new ArrayList<>();

        int len1 = num1.length(), len2 = num2.length();
        int i = len1 - 1, j = len2 - 1;

        int temp = 0;

        while (i >= 0 || j >= 0 || temp != 0) {
            int x = i >= 0 ? num1.charAt(i) - '0' : 0;
            int y = j >= 0 ? num2.charAt(j) - '0' : 0;

            int sum = x + y + temp;
            res.add(sum % 10);
            temp = sum / 10;

            i--;
            j--;
        }

        Collections.reverse(res);

        StringBuilder result = new StringBuilder();
        for (int d : res) {
            result.append(d);
        }
        return result.toString();

    }
}