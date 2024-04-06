#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

struct camel {
    int k;
    ll l, r;
};

int main() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<camel> train[n];
        int pos = 0;
        for (int i=0; i<n; i++) {
            camel c;
            cin >> c.k >> c.l >> c.r;
            c.k--;
            train[c.k].push_back(c);
            if (c.l > c.r) pos++;
        }
        ll ans = 0;

        auto pos_cmp = [](camel a, camel b) { return a.l - a.r < b.l - b.r; };
        priority_queue<camel, vector<camel>, decltype(pos_cmp)> pos_pq(pos_cmp);
        for (int i=n-1; i>=pos; i--) {
            for (auto &c:train[i])
                if (c.l > c.r)
                    pos_pq.push(c);
        }
        for (int i=pos-1; i>=0; i--) {
            for (auto &c:train[i])
                if (c.l > c.r)
                    pos_pq.push(c);
            if (!pos_pq.empty()) {
                ans += pos_pq.top().l;
                pos_pq.pop();
            }
        }
        while (!pos_pq.empty()) {
            ans += pos_pq.top().r;
            pos_pq.pop();
        }

        auto neg_cmp = [](camel a, camel b) { return a.r - a.l < b.r - b.l; };
        priority_queue<camel, vector<camel>, decltype(neg_cmp)> neg_pq(neg_cmp);
        for (int i=0; i<pos; i++) {
            for (auto &c:train[i])
                if (c.l <= c.r)
                    neg_pq.push(c);
        }
        for (int i=pos; i<n; i++) {
            if (!neg_pq.empty()) {
                ans += neg_pq.top().r;
                neg_pq.pop();
            }
            for (auto &c:train[i])
                if (c.l <= c.r)
                    neg_pq.push(c);
        }
        while (!neg_pq.empty()) {
            ans += neg_pq.top().l;
            neg_pq.pop();
        }
        
        cout << ans << '\n';
    }
    return 0;
}