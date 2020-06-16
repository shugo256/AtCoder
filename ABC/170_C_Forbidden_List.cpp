#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> p(110);
    iota(p.begin(), p.end(), 0);
    for (int i=0, pi; i<n; i++) {
        cin >> pi;
        p[pi] = -1000;
    }
    sort(p.begin(), p.end(), [&](int a, int b) {
        return P{abs(x - a), a} < P{abs(x-b), b};
    });
    cout << p[0] << '\n';
    return 0;
}