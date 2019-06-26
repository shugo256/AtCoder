#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

using P = pair<long, long>;

int main() {
    int n;
    cin >> n;
    set<P> s;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        s.insert(minmax({a, b}));
    }
    cout << s.size() << '\n';
    return 0;
}
