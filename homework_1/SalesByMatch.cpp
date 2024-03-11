int sockMerchant(int n, vector<int> ar) {
     std::sort(ar.begin(), ar.end()); 
    int number_of_pairs = 0;
    int i = 0;
    while (i < n - 1) {
        if (ar[i] == ar[i + 1]) { 
            number_of_pairs++;
            i += 2; 
        } else {
            i++; 
        }
    }

    return number_of_pairs;
  }
