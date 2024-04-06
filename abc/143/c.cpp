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
    char p = '\0';
    int ans = 0;
    for (auto &c:s) {
        if (c != p) ans++;
        p = c;
    }
    cout << ans << '\n';
    return 0;
}