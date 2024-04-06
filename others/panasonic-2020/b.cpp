#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll h, w;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << '\n';
        return 0;
    }
    cout << (h / 2) * w + (h % 2) * ((w + 1) / 2) << '\n';
    return 0;
}