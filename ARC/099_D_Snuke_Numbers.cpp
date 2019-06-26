#include <iostream>
#include <algorithm>

using namespace std;

//断念...

int main() {
    long k;
    cin >> k;
    long n = 0, d = 1, s = 0;
    for (int i=0; i<k; i++) {
        if (n / (10*d) == (n + d) / (10*d)) s++;
        else if ((n + d) > (s - 8) * d) {
            s++;
            d *= 10;
        } else s -= 8;
        n += d;
        cerr <<  s << ' ';
        cout << n << '\n';
    }
    return 0;
}