#include <iostream>
#include <string.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int superDigit(string n, int k) {
    if (n.size() == 1) return stoi(n);

    long  sum = 0;
    for (char c : n) {
        sum += (c - '0');
    }
    
    sum *= k;
    return superDigit(to_string(sum), 1);
}