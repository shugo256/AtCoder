#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long k, x, y;
    cin >> k >> x >> y;
    long sx = x / abs(x), sy = y / abs(y);
    x = abs(x); y = abs(y);
    if (k % 2 == 0 && (x + y) % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    long s = (x + y) / k;
    if ((x + y) % k == 0) {
        if (x % k == 0)
             cout  << s << '\n';
        else cout << s+1 << '\n';
        long i=0;
        for ( ; i+k<=x; i+=k)
            cout << sx*(i+k) << " 0" << '\n';
        long j=0;
        for ( ; j+k<=y; j+=k) 
            cout << sx*i << " " << sy*(j+k) << '\n';
        if (i != x)
            cout << sx*x << ' ' << sy*y << '\n';
        return 0;
    } else if ((x % k + y % k) % 2 == 0) {
        cout << s + 2 << '\n';
        long i = 0;
        for (; i+k <= x; i += k) cout << sx*(i+k) << " 0" << '\n';
        long j = 0;
        for (; j+k <= y; j += k) cout << sx*i << " " << sy*(j+k) << '\n';
        i += k;
        for (long a=0; a<=k; a++) {
            if (abs(i - a - x) + abs(j + a - y) == k) {
                cout << sx*(i-a) << ' ' << sy*(j+a) << '\n';
                cout << sx*x     << ' ' << sy*y     << '\n';
                break;
            }
        }
    } else  {
        cout << s + 3 << '\n';
        long i = 0;
        for (; i+k <= x; i += k) cout << sx * (i+k) << " 0" << '\n';
        long j = 0;
        for (; j+k <= y; j += k) cout << sx * i << " " << sy * (j+k) << '\n';
        long tarx = i + abs(i - x) + abs(j - y) - k,
             tary = j;
        i += k;
        cerr << tarx << ' ' << tary << '\n';
        for (long a = 0; a <= k; a++) {
            if (abs(i - a - tarx) + abs(j + a - tary) == k) {
                cout << sx * (i - a) << ' ' << sy * (j + a) << '\n';
                cout << sx * tarx    << ' ' << sy * tary    << '\n';
                break;
            }
            if (abs(i - a - tarx) + abs(j - a - tary) == k) {
                cout << sx * (i - a) << ' ' << sy * (j - a) << '\n';
                cout << sx * tarx << ' ' << sy * tary << '\n';
                break;
            }
            if (abs(i - 2*k + a - tarx) + abs(j + a - tary) == k) {
                cout << sx * (i - 2 * k + a) << ' ' << sy * (j + a) << '\n';
                cout << sx * tarx << ' ' << sy * tary << '\n';
                break;
            }
            if (abs(i - 2 * k + a - tarx) + abs(j - a - tary) == k) {
                cout << sx * (i - 2 * k + a) << ' ' << sy * (j - a) << '\n';
                cout << sx * tarx << ' ' << sy * tary << '\n';
                break;
            }
        }
        cout << sx*x << ' ' << sy*y << '\n';
    }
    return 0;
}