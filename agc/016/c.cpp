#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define LIMIT 1000000000

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (h * w == 1) {
        cout << "No" << '\n';
        return 0;
    }
    long unit = (LIMIT - 1) / (h*w - 1),
         minus = (H / h) * (W / w),
         plus = (H % h) * W + (W % w) * H - (H % h) * (W % w);
    if (minus >= plus * unit) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cout << (i % h == 0 && j % w == 0 ? -(unit * (h*w - 1) + 1): unit) << ' ';
        }
        cout << '\n';
    }
    return 0;
}