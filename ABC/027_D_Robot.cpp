#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    cin >> s;
    int dif = 0, move = 0;
    for (auto &c:s) {
        if (c == '+') dif++;
        else if (c == '-') dif--;
        else move++;
    }
    vector<int> moves;
    for (auto &c:s) {
        if (c == 'M') {
            moves.push_back(dif);
        } else if (c == '+') {
            dif++;
        } else {
            dif--;
        }
    }
    sort(moves.begin(), moves.end(), greater<int>());
    ll ans = 0;
    for (int i=0; i<move; i++) {
        if (i < move/2)
            ans += moves[i];
        else 
            ans -= moves[i];
    }
    cout << ans << '\n';
    return 0;
}