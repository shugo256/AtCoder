#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    string s, t;
    cin >> n >> s >> t;
    size_t i = 0;
    for ( ; i < n; i++)
        if (s.substr(i) == t.substr(0, n-i))
            break;
    cout << n + i << '\n';
    return 0;
}