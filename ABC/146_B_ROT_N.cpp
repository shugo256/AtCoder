#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (auto &c:s) {
        int a = c - 'A';
        a = (a + n) % 26;
        c = 'A' + a;
    }
    cout << s << '\n';
    return 0;
}