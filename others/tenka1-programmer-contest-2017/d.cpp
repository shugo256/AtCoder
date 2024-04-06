#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using ll = long long;

using namespace std;
using bs = bitset<30>;

int main() {
    int n, _k;
    cin >> n >> _k;
    bs k(_k), filled = (1 << 30) - 1;
    vector<bs> vars;
    vars.push_back(k);
    for ( ; (filled & k) != 0; filled <<= 1) {
        vars.push_back((filled & k).to_ulong() - 1);
        //cerr << vars.back() << '\n';
    }
    bs a;
    long _a, b, sum[31] = {0};
    for (int i=0; i<n; i++) {
        cin >> _a >> b;
        a = _a;
        int j=0;
        for (auto &v:vars) {
            if ((v | a) == v) sum[j] += b;
            j++;
        }
    }
    long _max = 0;
    for (auto &s:sum) _max = max(_max, s);
    cout << _max << '\n';
    return 0;
}