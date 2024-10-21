import java.util.Random;
import java.util.Scanner;

public class BinarySearch {

    private static final Random rand = new Random();

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

    public static int getValue(String text) {
        int res;
        Scanner sc = new Scanner(System.in);
        while (true) {
            try {
                System.out.println(text);
                res = Integer.parseInt(sc.nextLine());

                if (res > 0) {
                    break;
                } else {
                    System.out.println("input must be an integer > 0");
                }
            } catch (Exception e) {
                System.err.println("Invalid input, please enter a valid integer.");
            }
        }
        return res;
    }
  
    public static void QuickSort(int nums[], int left, int right){
        if(left < right){
            int pivotIndex = partition(nums, left, right);

            QuickSort(nums, left, pivotIndex - 1);
            QuickSort(nums, pivotIndex + 1, right);
        }
    }

    public static int partition(int nums[], int left, int right){
        int pivotIndex = left;
        int pivotVal = nums[pivotIndex];
        int storeIndex  = left +1;

        for(int i = left +1; i <= right; i++){
            if(nums[i] < pivotVal || nums[i] == pivotVal && rand.nextBoolean()){
                swap(nums, i, storeIndex);
                storeIndex++;
            }
           
        }
        swap(nums, pivotIndex, storeIndex-1);
        return storeIndex - 1;
    }
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int binarySearch(int nums[], int target) {
        int l =0, r = nums.length -1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int numsSize = getValue("Enter number of array: ");
        int nums[] = new int[numsSize];
        generateElement(nums, numsSize);
        System.out.println("Array after generation: ");
        QuickSort(nums, 0, nums.length - 1); //sorted list for binarySearch
        displayArr(nums);

        int target = getValue("Enter number to find: ");

        System.out.println("-----------------");

        int res = binarySearch(nums, target);
        if (res == -1) {
            System.out.println("Not found!");
        } else {
            System.out.println("Found at index: " + res);
        }
    }
}
