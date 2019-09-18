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
    priority_queue<long> pq;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        pq.push(a);
    }
    for (int i=0; i<m; i++) {
        long t = pq.top(); pq.pop();
        pq.push(t / 2);
    }
    long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    return 0;
}