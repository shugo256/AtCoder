#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    set<char> s;
    for (int i=0; i<3; i++) {
        char c; cin >> c;
        s.insert(c);
    }
    cout << (s.size() > 1 ? "Yes" : "No") << '\n';
    return 0;
}