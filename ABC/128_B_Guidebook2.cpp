#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

// mapのなかにpairのpriority_queue入れるのは流石にやばいので賢くスッキリver

int main() {
    int n;
    cin >> n;
    string s[n];
    int p[n];
    for (int i=0; i<n; i++) cin >> s[i] >> p[i];
    int idx[n]; 
    iota(idx, idx+n, 0); // 0, 1, 2, 3, 4, ...
    sort(idx, idx+n, [&](int l, int r) {
        return s[l] < s[r] || (s[l] == s[r] && p[l] > p[r]);
    });
    for (auto i:idx) cout << i + 1 << '\n';
    return 0;
}