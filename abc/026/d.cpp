#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;


int a, b, c;
double f(double t) {
    return a * t + b * sin(c * t * M_PI);
}

int main() {
    cin >> a >> b >> c;
    double l = 0, r = 200;
    for (int i=0; i<100; i++) {
        double m = (l + r) / 2;
        if (f(m) < 100) 
            l = m;
        else
            r = m;
    }
    cout << setprecision(15) << l << '\n';
    return 0;
}