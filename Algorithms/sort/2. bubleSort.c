/*
    Bubble Sort

    Complexity:
        Best case: O(n) - when the array has been sorted.
        Worst case: O(n^2) - when the array is reversed.
        Average case: O(n^2).
    
    Usage:
        1. Iterate through arrays: Compare each pair of adjacent elements  
            and swap them if they are not in the desired order.
        2. Repeat: Continue iterating through the array until there are 
            no more elements to swap.
*/

void swap(int *xp, int* yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
        
        for(int j = 0; j < size-i-1; j++)

            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1])


}

