long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);
    
    for(int i = 0; i < queries.size(); ++i){
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        
        arr[a - 1] += k;
        arr[b] -= k;
    }
    long max_val = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        max_val = max(max_val, sum);
    }
    return max_val;
}
