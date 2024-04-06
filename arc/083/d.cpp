#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 10000000000

using namespace std;

struct road { int i, j; long a; };

int main() {
    int n;
    cin >> n;
    vector<road> roads;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a; cin >> a;
            if (i >= j) continue;
            roads.push_back({i, j, a});
        }
    }
    sort(roads.begin(), roads.end(), [](road l, road r) {
        return l.a < r.a; 
    });
    long d[n][n], sum=0;
    fill(d[0], d[n], INF);
    for (int i=0; i<n; i++) d[i][i] = 0;
    for (auto r:roads) {
        int i = r.i, j = r.j;
        long a = r.a;
        cerr << i << ' ' << j << ' ' << a << '\n';
        if (d[i][j] > a) {
            for (int k=0; k<n; k++) {
                long d1 = d[i][k], d2 = d[j][k];
                d[i][k] = d[k][i] = min(d1, d2 + a);
                d[j][k] = d[k][j] = min(d2, d1 + a);
            }
            sum += a;
        } else if (d[i][j] < a) {
            sum = -1;
            break;
        }
    }
    cout << sum << '\n';
    return 0;
}