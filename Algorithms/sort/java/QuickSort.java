
public class QuickSort {

    public static void generateElement(int nums[], int sizeOfArr) {
        for (int i = 0; i < sizeOfArr; i++) {
            nums[i] = (int) (Math.random() * 10) + 1;
        }
    }

    public static void displayArr(int nums[]) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            if (i < nums.length - 1) {
                System.out.print(", ");
            } else {
                System.out.println(".");
            }
        }
    }

    public static void quickSortAlgo(int[] nums, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(nums, low, high);

            quickSortAlgo(nums, low, pivotIndex - 1);
            quickSortAlgo(nums, pivotIndex + 1, high);
        }
    }

    public static int partition(int nums[], int low, int high) {

        int pivotIndex = (low + high) / 2;
        int pivotVal = nums[pivotIndex];

        swap(nums, pivotIndex, low);

        int left = low + 1, right = high;
        while (left <= right) {

            while (left <= right && nums[left] <= pivotVal) {
                left++;
            }
            while (left <= right && nums[right] > pivotVal ) {
                right--;
            }
 
            if (left < right) {
                swap(nums, left, right);
            }
        }
        swap(nums, low, right);
        return right;
    }

    public static void swap(int nums[], int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    public static void main(String[] args) {

        int nums[] = new int[10];
        generateElement(nums, 10);
        System.out.println("Array after generation: ");
        displayArr(nums);

        quickSortAlgo(nums, 0, nums.length - 1);
        System.out.println("sorted : ");
        displayArr(nums);
        System.out.println("-----------------");

    }
}
