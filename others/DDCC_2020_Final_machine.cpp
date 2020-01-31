#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <cmath>

using ll = long long;

using namespace std;

bool isPrime[1000011];
vector<int> primes;
void computePrimes(int limit = 1000010) {             // #include <cassert>
    fill(isPrime, isPrime + limit + 1, true);  //最初全部trueにしておく
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i]){
            primes.push_back(i);
            if (primes.size() > 80000) return;
            for (int j = 2 * i; j <= limit; j += i) isPrime[j] = false;
        }
}

int beta(int alpha) {
    int r = primes[alpha] % 180;
    return min(r, 180 - r);
}

double a_time(double dif) {
    dif = abs(dif);
    if (dif / 200 >= 0.15)
        return dif / 200 + 150;
    else 
        return sqrt(dif * 3 / 1000);
}

const complex<double> Ac = {0., 900.},
                      Bc = {900., 0.},
                      Cc = {900., 900.};

int main() {
    int la, lb, lc, na, nb, nc, ne, ma, mb, mc, tc;
    cin >> la >> lb >> lc >> na >> nb >> nc >> ne >> ma >> mb >> mc >> tc;
    computePrimes();
    int t = 0, alpha = 0, port = 0;
    complex<double> cur = {0., 470.};
    double a_prev = 0;
    while (t < 80000) {
        complex<double> target;
        double Ta, dt = 0;
        if (port == 0) {
            complex<double> vec = cur - Ac;
            target = Ac + vec / abs(vec) * 900.;
            Ta = abs(arg(vec));
            dt = max(dt, a_time(Ta - a_prev));
            alpha += dt;
        } else if (port == 1) {
            complex<double> 
        }
        a_prev = Ta;
        port = (port+2) % 3;
    }
    cerr << tc << '\n';
    return 0;
}