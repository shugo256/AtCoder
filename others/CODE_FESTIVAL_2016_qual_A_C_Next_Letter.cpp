#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int l=-1;
    for (auto &c:s) {
        int opp = ('z' - c + 1) % 26;
        if (opp <= k) {
            k -= opp;
            c = 'a';
        }
        l++;
    }
    s[l] = (s[l] - 'a' + k) % 26 + 'a';
    cout << s << '\n';
    return 0;
}