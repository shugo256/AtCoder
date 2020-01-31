#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, nuki;
    cin >> s;
    int n = 0;
    vector<int> xp;
    for (auto c:s) {
        if (c == 'x') xp.push_back(n);
        else {
            n++;
            nuki += c;
        }
    }
    size_t len = nuki.size();
    for (size_t i=0; i<len; i++) {
        if (nuki[i] != nuki[len-i-1]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    if (xp.empty() || nuki.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    int i = 0, j = xp.size() - 1;
    int cnt=0;
    while (i <= j) {
        while (xp[i] + xp[j] > n)
            j--;
        if (i <= j && xp[i] + xp[j] == n) {
            cnt += (i == j ? 1 : 2);
            j--;
        }
        i++;
    }
    cout << xp.size() - cnt << '\n';
    return 0;
}