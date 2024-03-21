int makeAnagram(string a, string b) {
   int m = 0, n = 0;

    for (int i = 0; i < a.length(); ++i) {
        size_t pos = b.find(a[i]);
        if (pos != string::npos) {
            ++m; ++n;
            b.erase(pos, 1);
        }
    }

    int deletion_count = (a.length() + b.length() + n) - (2 * m);
    return deletion_count;

}
