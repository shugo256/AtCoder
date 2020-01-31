#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    n--;
    long dif = abs(a - b),
         q1 = (dif + n * c) / (c + d),
         q2 = (dif + n * d) / (c + d),
         r1 = (dif + n * c) % (c + d);
    if ((q1 < q2 && q1+1 <= n) || (r1 == 0 && q1 <= n))
        cout << "YES" << '\n';
    else 
        cout << "NO" << '\n';
    return 0;
}