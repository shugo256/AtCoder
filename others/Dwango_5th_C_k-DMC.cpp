#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> clist;
    long drui[n+1], mrui[n+1], dmrui[n+1];
    drui[0] = mrui[0] = dmrui[0] = 0;
    for (int i=0; i<n; i++) {
        char c = s[i];
        drui[i+1] = drui[i];
        mrui[i+1] = mrui[i];
        dmrui[i+1] = dmrui[i];
        if (c == 'D') 
            drui[i+1]++;
        else if (c == 'M') {
            mrui[i+1]++;
            dmrui[i+1] += drui[i];
        }
        else if (c == 'C')
            clist.push_back(i+1);
    }
    int q; cin >> q;
    for (int i=0, k; i<q; i++) {
        cin >> k;
        long sum = 0;
        for (auto end:clist) {
            int begin = max(end - k, 0);
            long dm = dmrui[end] - dmrui[begin],
                 d_m = drui[begin] * (mrui[end] - mrui[begin]);
            sum += dm - d_m;
        }
        cout << sum << '\n';
    }
    return 0;
}