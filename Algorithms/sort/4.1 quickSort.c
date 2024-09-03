/*
    Quick Sort - Lomuto

    Complexity:
        Best case: O(n log n) - This occurs when the pivot divides the array into two nearly equal halves.
        Worst case: O(n^2) - This occurs when the pivot is the smallest or largest element, leading to unbalanced partitions.
        Average case: O(n log n) - This is the expected time complexity for random pivots.

    Usage:
        1. Choose a pivot element from the array.
        2. Partition the array into two sub-arrays:
            - Elements less than or equal to the pivot.
            - Elements greater than the pivot.
        3. Recursively apply the above steps to the sub-arrays.
        4. Combine the results to get the sorted array.
*/



int partition(int arr[], int left, int right)
{
    int i = left - 1;
    int pivot = arr[right];

    for(int j = left; j < right; j++)
        if(arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    
    swap(arr[i+1], arr[right]);
    return i + 1;
    
}

void quickSort(int arr[], int left, int right)
{
    if(left >= right)   return;

    int pi = partition(arr, left, right);
    quickSort(arr, left, pi-1);
    quickSort(arr, pi+1, right);
}

