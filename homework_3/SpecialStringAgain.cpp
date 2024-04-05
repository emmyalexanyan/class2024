long substrCount(int n, string s) {
    long count = 0;
    vector<pair<char, long>> groups;
    long i = 0;
    while(i < n){
        long j = i + 1;
        while (j < n && s[j] == s[i]){
                j++;
        }
            groups.push_back(make_pair(s[i], j - i));
            i = j;
    }

    for (auto group : groups){
        count += (group.second * (group.second + 1)) / 2;
    }

    for (long i = 1; i < groups.size() - 1; i++){
        if (groups[i - 1].first == groups[i + 1].first && groups[i].second == 1)
            count += min(groups[i - 1].second, groups[i + 1].second);
    }

    return count;

}
