#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long comb2(long n) {
    if (n < 2) return 0;
    return (long)n * (n-1) / 2;
}

int main() {
    string s;
    long cnt[26] = {0};
    cin >> s;
    for (auto c:s) cnt[c-'a']++;
    long len = s.size(), sum = comb2(len) + 1;
    for (auto n:cnt) sum -= comb2(n);
    cout << sum << '\n';
    return 0;
}