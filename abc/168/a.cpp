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
    cin >> n;
    n %= 10;
    set<int> s{0, 1, 6, 8};
    if (n == 3) {
        cout << "bon" << '\n';
    } else if (s.count(n)) {
        cout << "pon" << '\n';
    } else {
        cout << "hon" << '\n';
    }
    return 0;
}