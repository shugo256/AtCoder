#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t n = s.size(), k = n/2;
    char c = s[k];
    for ( ; k<n; k++)
        if (s[k] != c || s[n - k - 1] != c) 
            break;
    cout << k << '\n';
    return 0;
}