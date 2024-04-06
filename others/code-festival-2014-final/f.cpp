#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a > b) {
        T buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b%a);
}

int check(vector<int> &invalid) {
    int cur = 0, ans = 0;
    for (auto &i:invalid) {
        if (i < cur) continue;
        cur = i + 3;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int b[n]; for (auto &bi:b) cin >> bi;
    vector<int> invalid;
    for (int i=0; i<n; i++) {
        int i1 = (i + 1) % n, i2 = (i + 2) % n;
        if (b[i1] % gcd(b[i], b[i2]) != 0) invalid.push_back(i);
    }
    int res1 = check(invalid);
    if (invalid[0] == 0 || invalid[0] == 1) {
        invalid.push_back(invalid[0] + n);
        invalid[0] = -1;
    }
    int res2 = check(invalid);
    if (invalid[1] == 1) {
        invalid.push_back(invalid[1] + n);
        invalid[1] = -1;
    }
    int res3 = check(invalid);
    cout << min({res1, res2, res3}) << '\n';
    return 0;
}