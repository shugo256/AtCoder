#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool yes = (n%2 == 0);
    for (int i=0; i<n/2; i++) {
        if (s[i] != s[i+n/2]) {
            yes = false;
            break;
        }
    }
    cout << (yes ? "Yes" : "No") << '\n';
    return 0;
}