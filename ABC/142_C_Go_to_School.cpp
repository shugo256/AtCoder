#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int ainv[n];
    for (int i=1, a; i<=n; i++) {
        cin >> a;
        a--;
        ainv[a] = i;
    }
    for (auto ai:ainv) cout << ai << ' ';
    cout << '\n';
    return 0;
}
