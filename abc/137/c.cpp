#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    unordered_map<string, long> cnt;
    for (auto &si:s) {
        cin >> si;
        sort(si.begin(), si.end());
        cnt[si]++;
    }
    long sum = 0;
    for (auto ci:cnt) {
        sum += ci.second * (ci.second - 1) / 2;
    }
    cout << sum << '\n';
    return 0;
}