long repeatedString(string s, long n) {
    long frequency = 0;
    for (char c : s) {
        if (c == 'a') {
            frequency++;
        }
    }
    
    long repeated_times = n / s.size();
    long remaining_chars = n % s.size();
    
    frequency *= repeated_times;
    
    for (int i = 0; i < remaining_chars; i++) {
        if (s[i] == 'a') {
            frequency++;
        }
    }
    return frequency;
}
