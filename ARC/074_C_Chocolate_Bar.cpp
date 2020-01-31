#include <iostream>
#include <algorithm>

using namespace std;

long dif(long a, long b, long c) {
    return max({a, b, c}) - min({a, b, c});
}

int main() {
    long h, w;
    cin >> h >> w;
    long best = min({
        ((h + 2) / 3 - h / 3) * w,
        ((w + 2) / 3 - w / 3) * h,
        dif(h * (w / 3),     (h / 2) * (w - w / 3),     (h + 1) / 2 * (w - w / 3)),
        dif(w * (h / 3),     (w / 2) * (h - h / 3),     (w + 1) / 2 * (h - h / 3)),
        dif(h * ((w+2) / 3), (h / 2) * (w - (w+2) / 3), (h + 1) / 2 * (w - (w+2) / 3)),
        dif(w * ((h+2) / 3), (w / 2) * (h - (h+2) / 3), (w + 1) / 2 * (h - (h+2) / 3))
    });
    cout << best << '\n';
    return 0;
}