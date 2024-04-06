#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<long, int>;
#define fi first
#define se second

#define MAX 100010

int main() {
    int n;
    cin >> n;
    long a[MAX], ma=0;
    vector<int> cans;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
        cans.push_back(i);
    }
    a[n] = 0;
    cans.push_back(n);
    sort(cans.begin(), cans.end(), [&](int l, int r) {
        if (a[l] != a[r]) return a[l] > a[r];
        else return l < r;
    });
    int begin=0, end=0, front=cans[0];
    long ans[n];
    fill(ans, ans+n, 0);
    //for (auto ca:cans) cerr << ca << ' ' << a[ca] << '\n';
    for ( ; begin<n; begin=end) {
        end = partition_point(cans.begin(), cans.end(), [&](int x) {
            return a[x] >= a[cans[begin]];
        }) - cans.begin();
        front = min(front, cans[begin]);
        //cerr << begin << ' ' << end << ' ' << front << '\n';
        ans[front] += end * (a[cans[begin]] - a[cans[end]]);
    }
    for (auto ansi:ans) cout << ansi << '\n';
    return 0;
}