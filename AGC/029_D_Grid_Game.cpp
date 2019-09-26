#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define x first
#define y second

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    P obs[n+1];
    for (int i=0; i<n; i++) cin >> obs[i].x >> obs[i].y;
    obs[n] = {h+1, 0};
    sort(obs, obs+n+1);
    int ofs = 0;
    for (auto &oi:obs) {
        if (oi.x > oi.y + ofs) {
            cout << oi.x - 1 << '\n';
            return 0;
        }
        else if (oi.x == oi.y + ofs) ofs++;
    }
    return 0;
}