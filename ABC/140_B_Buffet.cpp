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
    int a[n], b[n], c[n-1];
    for (auto &ai:a) {
        cin >> ai;
        ai--;
    }
    for (auto &bi:b)
        cin >> bi;
    for (auto &ci:c)
        cin >> ci;
    int prev = -100, sum=0;
    for (auto ai:a) {
        sum += b[ai];
        if (ai == prev + 1)
            sum += c[prev];
        prev = ai;
    }
    cout << sum << '\n';
    return 0;
}