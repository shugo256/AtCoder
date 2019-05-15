#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n, sum=0;
    cin >> n;
    for (long m=1; m<=n; m++) {
        if (n / m < m + 2) break;
        if (n%m != 0) continue;
        sum += n/m - 1;
    }
    cout << sum << '\n';
    return 0;
}
