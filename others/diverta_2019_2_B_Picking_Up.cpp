#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef pair<long, long> P;

int main() {
    size_t n;
    cin >> n;
    vector<P> balls;
    map<P, long> pqs;
    for (size_t i=0; i<n; i++) {
        long x, y; cin >> x >> y;
        for (size_t j=0; j<i; j++) {
            P ball = balls[j];
            long a = ball.first - x,
                 b = ball.second - y;
            if (a == 0 && b == 0) continue;
            if (a < 0) {
                a = -a;
                b = -b;
            }
            if (a == 0 && b < 0) b = -b;
            P ab = {a, b};
            if (pqs.find(ab) != pqs.end())
                pqs[ab]++;
            else
                pqs[ab] = 1;
        }
        balls.push_back({x, y});
    }
    long best = 0;
    for (auto pq:pqs) {
        best = max(best, pq.second);
    }
    cout << n - best << '\n';
    return 0;
}
