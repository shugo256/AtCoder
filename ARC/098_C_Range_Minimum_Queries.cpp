#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef priority_queue<int,vector<int>,greater<int>> minpq;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int a[n], best = 1000000000;
    for (auto &ai:a) cin >> ai;
    for (size_t t=0; t<n; t++) {
        int y = a[t];
        minpq chosen;
        for (int i=0; i<n; i++) {
            minpq buf;
            for ( ; y <= a[i] && i < n; i++)
                if (i != (int)t)
                    buf.push(a[i]);
            int len = (int)buf.size();
            for (int j=0; j<len-k+1; j++) {
                chosen.push(buf.top());
                buf.pop();
            }
        }
        int x = y;
        for (int i=0; i<q-1; i++) {
            if (chosen.empty()) {
                x = -1;
                break;
            } else {
                x = chosen.top();
                chosen.pop();
            }
        }
        if (x != -1)
            best = min(best, x-y);
    }
    cout << best << '\n';
    return 0;
}