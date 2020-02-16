#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    set<int> s{a, b, c};
    cout << (s.size() == 2 ? "Yes" : "No") << '\n';
    return 0;
}