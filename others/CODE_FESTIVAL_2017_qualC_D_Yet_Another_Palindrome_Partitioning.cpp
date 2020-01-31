#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <unordered_map>

using ll = long long;

using namespace std;

#define INF 200010

int dp[1 << 26];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> rui(1, 0);
    for (int i=0; i<len; i++) {
        rui.push_back(rui.back());
        rui.back() ^= (1 << (s[i] - 'a'));
    }
    fill(begin(dp), end(dp), INF);
    dp[0] = 0;
    for (int i=0; i<=len; i++) {
        for (int j=0; j<=26; j++) {
            int from = rui[i];
            if (j > 0) from ^= (1 << (j-1));
            dp[rui[i]] = min(dp[rui[i]], dp[from] + 1);
        }
    }
    cout << max(dp[rui[len]], 1) << '\n';
    return 0;
}
