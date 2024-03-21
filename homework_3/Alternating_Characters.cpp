int alternatingCharacters(string s) {
    int m = 0;
    
    for(int i=0; i < s.length(); ++i){
        if(s[i] == s[i+1]) m++;
    }

    return m;
}
