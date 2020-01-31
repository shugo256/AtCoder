#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int, greater<int>> m;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        m[ai]++;
    }
    int top = m.begin()->first, cnt=0;
    for (int i=top; i>=(top+1)/2; i--) {
        if ((i > top/2 && m[i] < 2) || (i == (top+1)/2 && m[i] > 2) || (i == top/2 && m[i] != 1)) {
            cnt = -1;
            break;
        }
        cnt += m[i];
    }
    cout << (cnt == n ? "Possible" : "Impossible") << '\n';
    return 0;
}