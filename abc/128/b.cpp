#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    map<string, priority_queue<P> > m;
    for (int i = 1; i <= n; i++) {
        string s;
        int p;
        cin >> s >> p;
        m[s].push({p, i});
    }
    for (auto &mi:m) {
        while (!mi.second.empty()) {
            P now = mi.second.top(); mi.second.pop();
            cout << now.second << '\n';
        }
    }
    return 0;
}
