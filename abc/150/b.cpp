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
    int ans = 0;
    for (int i=0; i<n-2; i++) {
        if (s.substr(i, 3) == "ABC") ans++;
    }
    cout << ans << '\n';
    return 0;
}