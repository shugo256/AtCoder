#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int a[n];
    for (auto &ai:a) {
        cin >> ai;
        sum += ai;
    }
    int cnt = 0;
    for (auto &ai:a) {
        if (ai * 4 * m >= sum) cnt++;
    }
    cout << (cnt >= m ? "Yes" : "No") << '\n';
    return 0;
}