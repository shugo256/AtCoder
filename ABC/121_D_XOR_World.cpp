#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long a, b;
    cin >> a >> b;
    b++;
    long d=1, ar=0, br=0, sum=0;
    while (b > 0) {
        ar += (a % 2) * d; br += (b % 2) * d;
        a /= 2; b /= 2;
        long ones = (b - a) * d + max(br-d, 0l) - max(ar-d, 0l);
        sum += (ones % 2) * d;
        d *= 2;
        // cerr << ar << ' ' << br << ' ' << ones << ' ' << d << '\n';
    }
    cout << sum << '\n';
    return 0;
}