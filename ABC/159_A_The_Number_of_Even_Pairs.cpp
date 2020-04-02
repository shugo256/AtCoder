#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n * (n-1) / 2 + m * (m-1) / 2 << '\n';
    return 0;
}