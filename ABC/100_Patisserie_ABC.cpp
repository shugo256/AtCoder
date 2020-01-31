#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using ll = long long;

using namespace std;

long sig[8][3] = {{ 1,  1,  1},
                  { 1,  1, -1},
                  { 1, -1,  1},
                  { 1, -1, -1},
                  {-1,  1,  1},
                  {-1,  1, -1},
                  {-1, -1,  1},
                  {-1, -1, -1}};

int main() {
    int n, m;
    cin >> n >> m;
    long val[8][1010] = {{0}};
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            long xyz; cin >> xyz;
            for (int k=0; k<8; k++) {
                val[k][i] += sig[k][j] * xyz;
            }
        }
    }
    long ans=0;
    for (int i=0; i<8; i++) {
        sort(val[i], val[i]+n, greater<long>());
        ans = max(ans, accumulate(val[i], val[i]+m, 0l));
    }
    cout << ans << '\n';
    return 0;
}