#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

bool isPrime[100011]; 
void computePrimes(int limit=100010) {
    assert(limit < 100011);                    // #include <cassert>
    fill(isPrime, isPrime + limit + 1, true);  //最初全部trueにしておく
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=limit; i++)
        if (isPrime[i])
            for (int j = 2 * i; j <= limit; j += i)
                isPrime[j] = false;
}

int main() {
    computePrimes();
    int q;
    cin >> q;
    int rui[100010] = {0};
    for (int i=1; i<50004; i++) {
        rui[2*i - 1] = rui[2*i] = rui[2*i - 2] + (isPrime[i] && isPrime[2*i - 1]);
    }
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        cout << rui[r] - rui[l-1] << '\n';
    }
    return 0;
}