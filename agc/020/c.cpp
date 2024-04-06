#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;

using B = bitset<4000001>;

int main() {
    int n;
    cin >> n;
    B dp;
    dp.set(0);
    int sum = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        sum += ai;
        dp |= (dp << ai);
    }
    for (int i=(sum+1)/2; i<=sum; i++) {
        if (dp[i]) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}