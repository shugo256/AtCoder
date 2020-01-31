#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int xors[30] = {0};
    for (int k=1; k<=n; k++) {
        long a, sum=0, d=1;
        cin >> a;
        for (int j=0; j<30; j++) {
            if (a%2) xors[j]++;
            a /= 2;
            sum += (xors[j] % 2 ? k - xors[j] : xors[j]) * d;
            // cerr << a << ' ' <<  xors[j] << '\n';
            d *= 2;
        }
        cout << sum << '\n';
    }
    return 0;
}