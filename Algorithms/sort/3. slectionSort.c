/*
    Selection Sort

    Complexity:
        Best case: O(n^2) - when the array has been sorted.
        Worst case: O(n^2) - when the array is reversed.
        Average case: O(n^2).

    Usage:
        1. Initialization: Suppose the first element of the array is the smallest element.
        2. Iterate through elements: Find the smallest element in the unsorted section.
        3. Swap: Swaps the smallest element with the first element of the unsorted part.
        4. Repeat: Move the boundary between the sorted and unsorted sections to the right
            of an element.
*/

void swap(int* xp, int* yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void selectionSort(int arr[], int size)
{
    int i, j, min_index;

    for(i = 0; i < size-1; i++){
        min_index = i;

        for(j = i+1; j < n; j++)
            if(arr[j] < arr[min_index])
                min_index = j;
        
        swap(&arr[i], &arr[min_index]);
    }

}