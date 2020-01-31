#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        int p; cin >> p;
        if (p != i) cnt++;
    }
    cout << (cnt <= 2 ? "YES" : "NO") << '\n';
    return 0;
}