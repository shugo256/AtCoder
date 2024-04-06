#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long gcd(long a, long b) {
    if (a > b) {
        long buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b % a);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
