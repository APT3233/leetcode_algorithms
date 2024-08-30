/*
    Linear Search
    
    Returns the position of the element to find in the array
    if not found, return -1
*/

int linearSearch(int arr[], int n, int target)
{
    int i = 0;
    while (i < n && arr[i] != target)
        i++;
    
    if(i == n)  return -1;

    return i;
}