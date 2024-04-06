#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long m, k;
    cin >> m >> k;
    long sum = 0, n=0;
    for ( ; sum < m; n++)
        sum += (2*sum + 1) * k;
    cout << n << '\n';
    return 0;
}