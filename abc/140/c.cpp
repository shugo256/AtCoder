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
    int ans=0, prev=100000000, cur;
    for (int i=0; i<n-1; i++) {
        cin >> cur;
        ans += min(prev, cur);
        prev = cur;
    }
    cout << ans + cur << '\n';
    return 0;
}