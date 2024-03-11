int jumpingOnClouds(vector<int> c) {
     int jumps = 0;
    int n = c.size(); 

    for (int i = 0; i < n - 1;) {
        if (i + 2 < n && c[i + 2] == 0) { 
            jumps++;
            i += 2; 
        } else if (c[i + 1] == 0) { 
            jumps++;
            i++; 
        } else break;
    }

    return jumps;
}
