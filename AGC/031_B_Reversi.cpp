#include <iostream>
#include <algorithm>

#define MAX 200010
#define mod (long)(1e9 + 7)

using namespace std;

int main() {
    int n; cin >> n;
    long cnt[MAX]={0}, clast[MAX];
    fill(clast, clast+MAX, -1);
    cnt[0] = 1;
    int prev=0;
    for (int i=1; i<=n; i++) {
        int c; cin >> c;
        cnt[i] = cnt[i-1];
        if (c != prev && clast[c] != -1)
            cnt[i] = (cnt[clast[c]] + cnt[i]) % mod;
        clast[c] = i;
        //cerr << "DEBUG" << ' ' <<  cnt[i] << '\n';
        prev = c;
    }
    cout << cnt[n] << '\n';
    return 0;
}