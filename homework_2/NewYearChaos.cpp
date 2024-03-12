void minimumBribes(vector<int> q) {
    int n = q.size();
    int bribes = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }

        for (int j = max(0, q[i] - 2); j < i; ++j) {
            if (q[j] > q[i]) {
                ++bribes;
            }
        }
    }

    cout << bribes << endl;
}
