
import java.util.Scanner;
public class LinearSearch {

    public static int linearSearch(int nums[], int tar) {
        int index = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == tar) {
                index = i;
                break;
            }
        }
        return index;
    }

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
                System.err.println(e);
            }
        }
        return res;
    }

    public static void main(String[] args) {

        int numsSize = getValue("Enter number of array: ");
        int nums[] = new int[numsSize];
        generateElement(nums, numsSize);
        System.out.println("arr after generate: ");
        displayArr(nums);

        int target = getValue("Enter number to find: ");

        System.out.println("-----------------");
        int res = linearSearch(nums, target);
        if (res == -1) {
            System.out.println("not found!");
        } else {
            System.out.println("found at index: " + res);
        }
    }
}
// linear search just return the first value found!