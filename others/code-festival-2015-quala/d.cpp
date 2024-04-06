#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long x[m];
    for (auto &xi:x)
        cin >> xi;
    long a = -1, b = 2*n;
    while (b - a > 1) {
        long t = (a + b + 1) / 2,
             car = 0; // 何両点検したか
        for (auto xi:x) {
            car++;
            long d = xi - car;
            if (d <= 0)
                car = max(car - 1, xi + t);
            else if (t >= d)
                car = xi + max(t - 2 * d, (t - d) / 2);
            else
                break;
        }
        if (car < n)
            a = t;
        else
            b = t;
    }
    cout << b << '\n';
    return 0;
}