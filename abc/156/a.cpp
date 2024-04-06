#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << (n < 10 ? k + 100 * (10 - n) : k) << '\n';
    return 0;
}