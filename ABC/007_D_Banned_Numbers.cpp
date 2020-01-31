#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

string to_8(ll si) {
    string s = to_string(si);
    string s8;
    bool eight = false;
    for (auto c:s) {
        if (eight) s8 += '8';
        else if (c == '4' || c == '9') {
            c--;
            s8 += c;
            eight = true;
        } 
        else s8 += c;
    }
    for (auto &c:s8) if (c >= '4') c--;
    return s8;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << b - a + 1 - (stoll(to_8(b), nullptr, 8) - stoll(to_8(a-1), nullptr, 8)) << '\n';
    return 0;
}