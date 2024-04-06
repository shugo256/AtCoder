#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

#define MAX 4010


void make_table(string &a, string &b, bool a_b[]) {
    int al = a.size(), bl = b.size();
    for (int i=0; i<MAX; i++) {
        a_b[i] = true;
        for (int j=0; j<bl && i+j<al; j++) {
            if (a[i+j] != '?' && b[j] != '?' && b[j] != a[i+j]) {
                a_b[i] = false;
                break;
            }
        }
    }
}

int solve(int &ans, string &a, string &b, string &c, bool a_b[], bool a_c[], bool b_c[]) {
    int al = a.size(), bl = b.size(), cl = c.size();
    for (int i=0; i<=al; i++) {
        for (int j=0; j<=bl || i+j<=al; j++) {
            if (a_b[i] && b_c[j] && a_c[i+j]) {
                ans = min(ans, max({i + j + cl, i + bl, al}));
            }
        }
    }
    return ans;
}

bool table[3][3][MAX];

int main() {
    string str[3];
    cin >> str[0] >> str[1] >> str[2];
    vector<int> id{0, 1, 2};
    int ans = str[0].size() + str[1].size() + str[2].size();
    do {
        make_table(str[id[0]], str[id[1]], table[id[0]][id[1]]);
    } while (next_permutation(id.begin(), id.end()));
    do {
        solve(ans, str[id[0]], str[id[1]], str[id[2]], table[id[0]][id[1]], table[id[0]][id[2]], table[id[1]][id[2]]);
    } while (next_permutation(id.begin(), id.end()));
    cout << ans << '\n';
    return 0;
}