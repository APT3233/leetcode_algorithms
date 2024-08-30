/*
    Insertion Sort

    Complexity:
        Best case: O(n) - when the array has been sorted.
        Worst case: O(n^2) - when the array is reversed.
        Average case: O(n^2).
    
    Usage:
        1. Initialization: Suppose the first element of the array has been sorted.
        2. Iterate through elements: Start from the second element, compare it to the 
            previous elements, and insert it in the appropriate place.
        3. Move elements: If the current element is smaller than the previous one,
            move the larger elements to a location to make room for the current element.
*/

void insertionSort(int arr[], int size)
{
    int i, key, j;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}