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
    int a = 1, b = m+1;
    while (b > a) {
        cout << a << ' ' << b << '\n';
        a++; b--;
    }
    a = m+2; b = 2*m+1;
    while (b > a) {
        cout << a << ' ' << b << '\n';
        a++; b--;
    }
    return 0;
}