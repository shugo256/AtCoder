#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <cmath>

using ll = long long;

using namespace std;

using BS = bitset<1000010>;

int main() {
    int n;
    string s, t = "";
    cin >> n >> s;
    bool one = false, two = false;
    for (int i=0; i<n-1; i++) {
        int c1 = s[i]-'0', c2 = s[i+1]-'0';
        char add = (char)(abs(c1 - c2) + '0');
        t += add;
        if (add == '1') one = true;
        if (add == '2') two = true;
    }
    if (n == 2) {
        cout << t[0] << '\n';
        return 0;
    }
    if (one) {
        BS bs;
        for (int i=0; i<n-1; i++) bs[i] = (t[i] == '1');
        int m = n-2, d = (1 << 30);
        while (m) {
            if (m >= d) {
                bs ^= (bs >> d);
                m -= d;
            }
            d /= 2;
        }
        cout << (bs[0] ? '1' : '0') << '\n';
    }
    else if (two) {
        BS bs;
        for (int i=0; i<n-1; i++) bs[i] = (t[i] == '2');
        int m = n-2, d = (1 << 30);
        while (m) {
            if (m >= d) {
                bs ^= (bs >> d);
                m -= d;
            }
            d /= 2;
        }
        cout << (bs[0] ? '2' : '0') << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}