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
    int cnt = 0;
    for (int i=0, a; i<n; i++) {
        cin >> a;
        if (a == cnt+1) cnt++;
    }
    cout << (cnt > 0 ? n - cnt : -1) << '\n';
    return 0;
}