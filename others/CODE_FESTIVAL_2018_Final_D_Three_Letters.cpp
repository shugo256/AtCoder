#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i=0; i<n; i++) {
        string s;
        unordered_map<string, bool> one, two, three;
        cin >> s;
        for (auto c:s) {
            for (auto &s2:two) {
                string sum = s2.first+c;
                if (!three[sum]) {
                    three[sum] = true;
                    cnt[sum]++;
                }
            }
            for (auto &s1:one) {
                string sum = s1.first+c;
                if (!two[sum])
                    two[sum] = true;
            }
            one[string(1, c)] = true;
        }
    }
    int best = 0;
    string ans;
    for (auto &c:cnt) {
        if (best < c.second) {
            ans = c.first;
            best = c.second;
        }
    }
    cout << ans << '\n';
    return 0;
}