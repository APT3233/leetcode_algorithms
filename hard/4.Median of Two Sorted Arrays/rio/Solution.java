


//bruce force method for this solution!


class Solution {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] res = mergeList(nums1, nums2);
        int tmp = 0;
        if (res.length % 2 != 0) {
            int medIndex = (res.length) / 2;
            System.out.println("Median index when res is odd:  " + medIndex);
            double result = (double)(res[medIndex]);
            return result;
        } else {
            int medIndex = (res.length) / 2;
            System.out.println("Median index when res is even: " + medIndex);
            System.out.println("value of that index: " + res[medIndex]);
            int prev = medIndex - 1;
            System.out.println("Value of the next index: " + res[prev]);

            double result = (double)(res[medIndex] + res[prev]) / 2;
            return result;
        }
    }

    public int[] mergeList(int[] a, int[] b) {
        int sizeA = a.length;
        int sizeB = b.length;

        int[] res = new int[sizeA + sizeB];

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < sizeA && j < sizeB) {
            if (a[i] < b[j]) {
                res[k] = a[i];
                System.out.print("1");
                i++;
            } else {
                res[k] = b[j];
                System.out.print("2");
                j++;
            }
            k++;
        }
        while (i < sizeA) {
            res[k] = a[i];
            k++;
            i++;
        }

        while (j < sizeB) {
            res[k] = b[j];
            k++;
            j++;
        }

        // System.out.println("list:  ");
        // for (int z = 0; z < res.length; z++) {
        //     System.out.print("" + res[z] + " ");
        // }
        return res;
    }

    public static void main(String[] args) {
        // int[] nums1 = {1, 3, 5, 7};
        // int[] nums2 = {2, 6, 9, 8};


        // int[] nums1 = {1, 2, 3};
        // int[] nums2 = {2, 4};

        int[] nums1 = {1, 3, 5, 7, 10, 11, 12};
        int[] nums2 = {2, 6, 9};


        Solution s = new Solution();
        double res = s.findMedianSortedArrays(nums1, nums2);
        System.out.println("median: " + res);
    }
}
