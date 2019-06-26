#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>


using namespace std;

int main() {
    long w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << setprecision(10) << (double)(w * h) / 2.0 << ' ' << (w == x*2 && h == y*2) << '\n';
    return 0;
}
