#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

using ll = long long;

using namespace std;

using P = pair<long, long>;
#define fi first
#define se second

bool used[8] = {0};
int n;
P xy[8]; 

double dist(int i, int j) {
    if (i < 0 || j < 0) return 0;
    long xd = xy[i].fi - xy[j].fi,
         yd = xy[i].se - xy[j].se;
    return sqrt(xd * xd + yd * yd);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> xy[i].fi >> xy[i].se;
    double sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            sum += dist(i, j) * 2 / n;
        }
    }
    cout << setprecision(15) << sum << '\n';
    return 0;
}