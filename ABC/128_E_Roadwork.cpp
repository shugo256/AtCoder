#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct T{int a, b, c;};

int main() {
    int n, q;
    cin >> n >> q;
    vector<T> times;
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        times.push_back({s - x, 1, x});
        times.push_back({t - x, 2, x});
    }
    for (int i = 0; i < q; i++) {
        int d; cin >> d;
        times.push_back({d, 0, 0});
    }
    sort(times.begin(), times.end(), [](T l, T r) { 
        return l.a < r.a || (l.a == r.a && l.b > r.b); 
    });
    set<int> s;
    for (auto t:times) {
        if (t.b == 1)
            s.insert(t.c);
        else if (t.b == 2)
            s.erase(t.c);
        else
            cout << (s.empty() ? -1 : *(s.begin())) << '\n';
    }
    return 0;
}
