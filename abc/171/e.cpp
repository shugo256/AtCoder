#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    int a[n]; for (auto &ai:a) {
        cin >> ai;
        total ^= ai;
    }
    for (auto &ai:a) {
        cout << (ai ^ total) << ' ';
    }
    cout << '\n';
    return 0;
}