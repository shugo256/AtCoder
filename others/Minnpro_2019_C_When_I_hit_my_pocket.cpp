#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long k, a, b;
    cin >> k >> a >> b;
    cout << ((k > a - 1 && b - a >= 2)
                 ? a + ((k - (a - 1)) / 2) * (b - a) + (k - (a - 1)) % 2
                 : k + 1)
         << '\n';
    return 0;
}