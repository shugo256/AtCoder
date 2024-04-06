#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using ll = long long;

#define onWall(x, y) (x % r == 0 || y % c == 0)

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<int> wall;
    P points[200000];
    for (int i=0, x1, x2, y1, y2; i<n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        points[i] = {x1, y1};
        points[i+n] = {x2, y2};
        if (onWall(x1, y1) && onWall(x2, y2)) {
            wall.push_back(i);
            wall.push_back(i+n);
        }
    }
    auto to_line = [&](P p){
        int x = p.fi, y = p.se;
        if (y==0) return x;
        if (x==r) return r+y;
        if (y==c) return r+c+r-x;
        return r+c+r+c-y;
    };
    sort(wall.begin(), wall.end(), [&](int a, int b) {
        P ap = points[a], bp = points[b];
        return to_line(ap) < to_line(bp);
    });
    stack<int> st;
    for (auto w:wall) {
        w %= n;
        if (!st.empty() && w == st.top()) st.pop();
        else st.push(w);
    }
    cout << (st.empty() ? "YES" : "NO") << '\n';
    return 0;
}