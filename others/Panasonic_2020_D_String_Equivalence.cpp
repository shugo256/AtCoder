#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

using P = pair<string, char>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    set<P> s[n+1];
    s[0].insert({"", 'a'});
    for (int i=0; i<n; i++) {
        for (auto &p:s[i]) {
            for (char c='a'; c<=p.se; c++) {
                s[i+1].insert({p.fi + c, max((char)(c+1), p.se)});
            }
        }
    }
    for (auto &p:s[n]) cout << p.fi << '\n';
    return 0;
}