#include <iostream>
#include <algorithm>
#include <complex>

using namespace std;

struct point_t {
    complex<double> c;
    double &x = reinterpret_cast<double*>(&c)[0];
    double &y = reinterpret_cast<double*>(&c)[1];
    point_t(double x, double y) :c(x, y) {}
    point_t(complex<double> c) :c(c) {}
};

int main() {
    point_t p(1, 2), q(complex<double>{3, 4});
    cout << p.x << ' ' << p.y << endl;
    cout << q.x << ' ' << q.y << endl;
    p = q;
    cout << p.x << ' ' << p.y << endl;
    cout << q.x << ' ' << q.y << endl;
    return 0;
}