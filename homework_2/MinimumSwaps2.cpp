int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int swaps = 0;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] != (i + 1)) {
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            swaps++;
            i--; 
        }
    }
    return swaps;
}
