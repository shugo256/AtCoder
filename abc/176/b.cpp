#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string n;
    cin >> n;
    int ans = 0;
    for (auto c:n) {
        ans += c - '0';
        ans %= 9;
    }
    cout << (ans == 0 ? "Yes" : "No") << '\n';
    return 0;
}