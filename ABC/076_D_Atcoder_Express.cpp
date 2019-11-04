#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

int diagram[40010] = {0};
int main() {
    int n;
    cin >> n;
    int t[n], v[n];
    for (auto &ti:t) cin >> ti;
    for (auto &vi:v) cin >> vi;
    int j = 0;
    for (int i=0, s; i<n; i++) {
        s = j;
        for (; j<s+t[i]*2; j++) {
            diagram[j] = v[i] * 2;
        }
    }
    int prev = 0;
    for (auto &d:diagram) {
        d = min(prev+1, d);
        prev = d;
    }
    for (int i=0, s=0; i<n; i++) {
        s += t[i] * 2;
        if (i < n-1 && diagram[s-1] <= 2 * v[i+1]) continue;
        diagram[s] = diagram[s-1] = (i < n-1 ? v[i+1] * 2 : 0);
    }
    reverse(diagram, diagram+40010);
    prev = 0;
    long ans = 0;
    for (auto &d:diagram) {
        prev = min(prev+1, d);
        ans += prev;
    }
    cout << setprecision(15) << (double)ans / 4  << '\n';
    return 0;
}