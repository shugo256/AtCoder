#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int l, r;
unordered_map<long, long> cnt;
int wl[16], wr[16];
long ans = 0, x;

void dfs(int mode, int i=0, int sum=0) {
    if (i == (mode ? l : r)) {
        if (mode)
            cnt[sum]++;
        else
            ans += cnt[x - sum];
    }
    else {
        dfs(mode, i+1, sum);
        dfs(mode, i+1, sum+(mode ? wl[i] : wr[i]));
    }
}

int main() {
    int n;
    cin >> n >> x;
    l = n/2; r = n - l;
    for (int i=0; i<l; i++) cin >> wl[i];
    for (int i=0; i<r; i++) cin >> wr[i];
    dfs(1);
    dfs(0);
    cout << ans << '\n';
    return 0;
}