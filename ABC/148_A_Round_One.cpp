#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    set<int> s{1, 2, 3};
    s.erase(a);
    s.erase(b);
    cout << *s.begin() << '\n';
    return 0;
}