#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    long n;
    cin >> n;
    n++;
    bool win = true;
    while (n > 1) {
        n += (long) win;
        n >>= 1;
        win ^= 1;
    }
    cout << (win ? "Takahashi" : "Aoki") << '\n';
    return 0;
}