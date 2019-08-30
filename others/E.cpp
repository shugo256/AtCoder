#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define long long long

using namespace std;
using P = pair<long, long>;

int main() {
    long n, h, w;
    cin >> n >> h >> w;
    priority_queue<P> pq[h + w];
    for (int i=0; i<n; i++) {
        long r, c, a;
        cin >> r >> c >> a;
        r--; c--;
        pq[r].push({a, h+c});
        pq[h+c].push({a, r});
    }
    long sum = 0;
    bool done[h+w];
    fill(done, done+h+w, false);
    for (int i=0; i<h+w; i++) {
        if (done[i]) continue;
        P p1 = pq[i].top(); pq[i].pop();
        int j = p1.second;
        P p2 = pq[i].top(),
          c1 = pq[j].top();
        if (c1.first <= p1.first)  {
            pq[j].pop();
            P c2 = pq[j].top();
            if (c2.first == p1.first) {
                vector<P> buf;
                while (c1.second != p1.second) {
                    buf.push_back(c1);
                    c2 = c1;
                    c1 = pq[j].top(); pq[j].pop();
                }
                for (auto b:buf) pq[j].push(b);
            }
            if (c2.first < p2.first) {
                sum += p2.first;
                pq[i].pop();
            } else {
                sum += c2.first;
            }
            done[j] = true;
        }
        sum += p1.first;
        done[i] = true;
    }
    cout << sum << '\n';
    return 0;
}