#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n;
    set<int> s;
    cin >> n;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        s.insert(ai);
    }
    cout << (s.size() == n ? "YES" : "NO") << '\n';
    return 0;
}