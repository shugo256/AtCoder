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
    int cnt[n];
    fill(cnt, cnt+n, 0);
    for (int i=0, ai; i<n-1; i++) {
        cin >> ai;
        cnt[ai-1]++;
    }
    for (auto &ci:cnt) cout << ci << '\n';
    return 0;
}