#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b[m];
    for (int i=0; i<n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        if (ai <= m)
            b[ai - 1].push_back(bi);
    }
    priority_queue<int> pq;
    int sum = 0;
    for (auto &bi:b) {
        for (auto &bij:bi) pq.push(bij);
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
    return 0;
}