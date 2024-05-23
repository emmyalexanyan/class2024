#include <iostream>
#include <string.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int stepPerms(int n) {
  
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;

    return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
}
