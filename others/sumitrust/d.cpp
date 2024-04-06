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
    string s;
    cin >> n >> s;
    set<string> l1, l2, l3;
    for (auto &c:s) {
        for (auto &t2:l2) l3.insert(t2 + c);
        for (auto &t1:l1) l2.insert(t1 + c);
        l1.insert(string(1, c));
    }
    cout << l3.size() << '\n';
    return 0;
}