#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int l = max(h, w);
    cout << (n + l - 1) / l << '\n';
    return 0;
}