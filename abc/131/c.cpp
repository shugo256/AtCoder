#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

long lcm(long N, long M) {
    if (N < M) return lcm(M, N);
    long product = N * M, buf;
    while (M != 0) {
        buf = N;
        N = M;
        M = buf % M;
    }
    return product / N;
}

int main() {
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    long ccnt = b / c - (a - 1) / c,
         dcnt = b / d - (a - 1) / d,
         cdcnt = b / lcm(c, d) - (a - 1) / lcm(c, d);
    cout << b - a - (ccnt + dcnt - cdcnt) + 1 << '\n';
    return 0;
}
