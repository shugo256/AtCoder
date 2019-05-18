#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n, a, b;
    cin >> n >> a >> b;
    if (n + 1 < a + b || n > a * b) {
        cout << -1 << '\n';
        return 0;
    }
    long start = n + 1, 
        sets  = (b == 1 ? 0 : (n - a) / (b - 1)), 
        r     = (b == 1 ? 0 : (n - a) % (b - 1));
    for (long i=0; i<b; i++) {
        long end = start;
        if (i == b-1)
            start = 1;
        else
            start -= sets + (i < r);
        for (long j=start ; j<end; j++) 
            cout << j << (j < end-1 || i < b-1 ? ' ' : '\n');
    }
    return 0;
}