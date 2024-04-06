#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

#define amax(a, b) a = max(a, b)

int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    int jump[n], rjump[n];
    int prev = n;
    bool work[n];
    for (int i=n-1; i>=0; i--) {
        work[i] = (s[i] == 'o');
        if (s[i] == 'o') {
            prev = i;
            jump[i] = i;
        } else {
            jump[i] = prev;
        }
    }
    prev = -1;
    for (int i=0; i<n; i++) {
        if (work[i]) {
            rjump[i] = i;
            prev = i;
        } else {
            rjump[i] = prev;
        }
        // cerr << rjump[i] << '\n';
    }
    int left[n+1], right[n+1];
    fill(left, left+n+1, 0);
    fill(right, right+n+1, 0);
    for (int i=0; i<n-1; i++) {
        if (work[i]) {
            amax(left[i], 1); // 最初対策
            if (i+c+1 < n && jump[i+c+1] < n)
                amax(left[jump[i+c+1]], left[i] + 1);
        }
        amax(left[i+1], left[i]);
    }
    for (int i=n-1; i>=1; i--) {
        if (work[i]) {
            amax(right[i], 1); // 最初対策
            if (i-c-1 >= 0 && rjump[i-c-1] >= 0)
                amax(right[rjump[i-c-1]], right[i] + 1);
        }
        amax(right[i-1], right[i]);
    }
    for (int i=0; i<n; i++) {
        // cerr << (i > 0 ? left[i-1] : 0) << ' ' << right[i+1] << '\n';
        if (work[i] && (i > 0 ? left[i-1] : 0) + right[i+1] < k) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}