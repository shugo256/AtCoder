#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int pow2(int n) {
    int ans = 1;
    while (n > 0) {
        if (n % 2) return ans;
        n /= 2;
        ans *= 2;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    if (n < 3 || pow2(n) == n) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    cout << 1+n << ' ' << 2+n << '\n';
    for (int i=1; i<=(n-1)/2; i++) {
        cout << 1     << ' ' << 2*i << '\n';
        cout << 2*i   << ' ' << 2*i+1 << '\n';
        cout << 1     << ' ' << 2*i+1+n << '\n';
        cout << 2*i+n << ' ' << 2*i+1+n << '\n';
    }
    if (n % 2 == 0) {
        cout << pow2(n) * 2 - 2 << ' ' << n << '\n';
        cout << 2*n-1 << ' ' << 2*n << '\n';
    }
    return 0;
}
