#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    x1 -= x0; x2 -= x0;
    y1 -= y0; y2 -= y0;
    int si = abs(x1*y2 - x2*y1),
        ai = x1*x1 + y1*y1,
        bi = x2*x2 + y2*y2,
        ci = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    double h = sqrt((double)si*si / max({ai, bi, ci})),
           s = si,
           a = sqrt(ai),
           b = sqrt(bi),
           c = sqrt(ci);
    cout << setprecision(15) << s / (a + b + c + 2*h) << '\n';
    return 0;
}