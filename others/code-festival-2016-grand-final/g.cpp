#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using ll = long long;

using namespace std;

int main() {
    long k;
    cin >> k;
    vector<long> comb(500);
    comb[0] = 1;
    for (int i=1; i<500; i++) comb[i] = comb[i-1] * (i+7) / i;
    reverse(comb.begin(), comb.end());
    string ans = "";
    for (auto c:comb) {
        ans += string(k / c, 'F') + "ESTIVAL";
        k %= c;
    }
    cout << ans << '\n';
    return 0;
}