vector<int> rotLeft(vector<int> a, int d) {
    int m = 0, temp;
    int n = a.size();
    while(m < d){
        temp = a[0];
        for(int i = 0; i < n; ++i){
            a[i] = a[i+1];}
        a[n-1] = temp;
        m++;
    }
    return a;
}
