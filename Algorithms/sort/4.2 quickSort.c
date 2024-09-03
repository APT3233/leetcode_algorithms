/*
    Quick Sort - Hoare

    Complexity:
        Best case: O(n log n) - This occurs when the pivot divides the array into two nearly equal halves.
        Worst case: O(n^2) - This occurs when the pivot is the smallest or largest element, leading to unbalanced partitions.
        Average case: O(n log n) - This is the expected time complexity for random pivots.

    Usage:
        1. Initialization: Choose a pivot element from the array (commonly the first element).
        2. Partition: Use two pointers, one starting from the beginning and one from the end of the array. Move the pointers towards each other, swapping elements to ensure all elements less than the pivot are on the left and all elements greater are on the right.
        3. Recursion: Recursively apply Quick Sort to the sub-arrays formed by the partition.
        4. Combine: Combine the results to get the sorted array.
*/

int partition(int arr[], int left, int right)
{
    int pivot  = arr[left];
    int i = left - 1;
    int j = right + 1;

    while(1){

        do{
            ++i
        }while(arr[i] < pivot)
        do{
            --j;
        }while(arr[j] > pivot)

        if(i < j)
            swap(a[i], a[j]);

        else
            return j;
    }
}

void quickSort(int arr[], int left, int right)
{
    if(left >= right)   return;

    int p = partition(arr, left, right);
    quickSort(arr, left, p);
    quickSort(arr, p+1, right);
}