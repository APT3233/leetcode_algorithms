/*
    Interpolation Search  O(log(log(n)))
    
    1. Assign left = 0, right = n – 1.
    2. Assign mid = left + (right – left) * (x – a[left]) / (a[right] – a[left]):
        If A[mid] == x:
            Stops and returns the value of mid.
        If A[mid] > x:
            right = mid – 1
        If A[mid] < x:
            left = mid + 1
    3. If left <= right and x >= A[left] and x <= A[right] (x is still in the paragraph [A[left]; A[right]]):
        If correct, go back to step 2.
        If false, stop and return result -1 (x not found)
*/

int interpolationSearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right && x >= arr[left] && x <= arr[right])
    {
        mid = left + (right - left) * (x - A[left]) / (arr[right] - arr[left]);
        
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            right = mid - 1;

        else if (arr[mid] < x)
            left = mid + 1;
    }
    
    return -1; 
}