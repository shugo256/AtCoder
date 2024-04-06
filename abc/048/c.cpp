#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    long cnt = 0, prev = 0;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        long dif = max(0l, prev + a - x);
        cnt += dif;
        prev = a - dif;
    }
    cout << cnt << '\n';
    return 0;
}