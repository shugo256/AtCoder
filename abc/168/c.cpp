#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <cmath>
#include <iomanip>

using ll = long long;

using namespace std;

using C = complex<double>;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    C jisin = {(double)a, 0.}, funsin = {(double) b, 0.};
    double time = h * 60 + m;
    jisin  *= exp( complex< double >( .0, (time * 0.5) * M_PI / 180.0 ) );
    funsin *= exp( complex< double >( .0, (time * 6.0) * M_PI / 180.0 ) );
    cout << setprecision(15) << fixed << abs(jisin - funsin) << '\n';
    return 0;
}