#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n], b[n];
    bool done[n];
    int dcnt=0;
    fill(done, done+n, false);
    for (auto &ai:a)
        cin >> ai;
    for (int i=0; i<n; i++) {
        cin >> b[i];
        if (b[i] == a[i]) {
            done[i] = true;
            dcnt++;
        } else if (b[i] < a[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    long cnt=0;
    while (dcnt < n) {
        bool no = true;
        for (int i=0; i<n; i++) {
            if (done[i]) continue;
            int ip = (i + n - 1) % n,
                in = (i + 1) % n;
            long q = (b[i] - a[i]) / (b[ip] + b[in]);
            if (q > 0) no = false;
            else continue;
            cnt += q;
            b[i] -= (b[ip] + b[in]) * q;
            if (b[i] == a[i]) {
                done[i] = true;
                dcnt++;
            }
        }
        if (no) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}