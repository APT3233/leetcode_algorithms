/*
    Binary Search
    
    1. Assign left = 0, right = n – 1.
    2. Assign mid = (left + right) / 2 (get the integer part, this is the middle element of the current interval)
        If A[mid] == x:
            Stops and returns the value of mid (which is the position of x in array A).
        If A[mid] > x (possibly x is in the previous half of the interval):
            right = mid – 1 // limit the search range to half the previous range
        If A[mid] < x (possibly x is in the second half of the interval):
            left = mid + 1 // limit the search range to the second half of the range
    3. If left <= right:
        If correct, go back to step 2 (can still divide in half).
        If false, stop and return result -1 (x not found)
*/

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;

        if(target > arr[mid])
            left = mid + 1;
        else if(target < arr[mid])
            right = mid - 1;
    }

    return -1;
    
}