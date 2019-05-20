#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct tv {
    int s, t, c;
};

bool operator<(const tv& l, const tv& r) {
    return l.s < r.s;
}

int main() {
    int n, c;
    cin >> n >> c;
    tv progs[n];
    for (auto &p:progs)
        cin >> p.s >> p.t >> p.c;
    sort(progs, progs+n);
    auto compt = [](tv l, tv r) { return l.t > r.t; };
    priority_queue<tv, vector<tv>, decltype(compt)> pq(compt);
    for (auto p:progs) {
        if (!pq.empty()) {
            tv end = pq.top(); pq.pop();
            if (end.t < p.s || (end.c == p.c && end.t == p.s)) {
                pq.push({end.s, p.t, p.c});
                continue;
            }
            pq.push(end);
        }
        pq.push(p);
    }
    cout << pq.size() << '\n';
    return 0;
}