#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int h[n];
    for (auto &hi:h) cin >> hi;
    long l = 0, r = (long)1e9;
    while (r - l > 1) {
        long c = (l + r + 1) / 2, sum=0;
        for (auto hi:h)
            if (hi > b * c)
                sum += (hi - b * c - 1) / (a - b) + 1;
        if (c < sum) l = c;
        else r = c;
    }
    cout <<  r << '\n';
    return 0;
}