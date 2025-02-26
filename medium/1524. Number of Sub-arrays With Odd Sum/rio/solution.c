int numOfSubarrays(int* arr, int arrSize){
    long long oddCounting = 0, prefixSum = 0;
    for(int i = 0; i < arrSize; i++){
        prefixSum += arr[i];
        oddCounting += prefixSum %2;
    }

    oddCounting += (arrSize - oddCounting) * oddCounting;
    return (int)(oddCounting % 1000000007);
}

//idea: using prefix sum to determine sum of subarr, reduce time complexity