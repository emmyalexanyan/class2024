int commonChild(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    vector<int> currentRow(n + 1, 0);
    vector<int> previousRow(n + 1, 0);
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                currentRow[j] = previousRow[j - 1] + 1;
            } else {
                currentRow[j] = max(currentRow[j - 1], previousRow[j]);
            }
        }
        
        swap(currentRow, previousRow);
    }
    return previousRow[n];
}
