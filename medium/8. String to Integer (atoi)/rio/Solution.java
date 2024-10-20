class Solution {
    public static int myAtoi(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int i = 0;
        int ans = 0;
        boolean isNegative = false;
        int n = s.length();

        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        if (i == n) {
            return 0;
        }

        if (s.charAt(i) == '-' || s.charAt(i) == '+') {
            if (s.charAt(i) == '-') {
                isNegative = true;
            }
            i++;
        }

        while (i < n && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            int tmp = s.charAt(i) - '0';

            if (ans > (Integer.MAX_VALUE - tmp) / 10) {
                return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }

            ans = ans * 10 + tmp;
            i++;
        }

        if (isNegative) {
            ans = -ans;
        }

        return ans;
    }
}
