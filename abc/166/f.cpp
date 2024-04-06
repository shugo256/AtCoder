#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

bool contains(string s, char a) {
    return s[0] == a || s[1] == a;
}
void choose(char plus, char minus, map<char, int> &var, string &ans) {
    var[plus]++; var[minus]--;
    ans += plus;
}

int main() {
    int n;
    map<char, int> var;
    cin >> n >> var['A'] >> var['B'] >> var['C'];
    string s[n], ans;
    for (int i=0; i<n; i++) cin >> s[i];
    bool yes = true;
    for (int i=0; i<n; i++) {
        char x = s[i][0], y = s[i][1];
        if (var[x] < 0 || var[y] < 0 || (var[x] == 0 && var[y] == 0)) {
            yes = false;
            break;
        }
        if (var[x] == 0)                         choose(x, y, var, ans);
        else if (var[y] == 0)                    choose(y, x, var, ans);
        else if (i < n-1 && contains(s[i+1], x)) choose(x, y, var, ans);
        else                                     choose(y, x, var, ans);
    }
    if (var['A'] < 0 || var['B'] < 0 || var['C'] < 0) yes = false;
    cout << (yes ? "Yes" : "No") << '\n';
    if (yes) {
        for (auto &ai:ans) cout << ai << '\n';
    }
    return 0;
}