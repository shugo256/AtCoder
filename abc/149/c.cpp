#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

// 素数判定 2からfor分で回して行く limitはどこまでやるか エラトステネスの篩
bool isPrime[100101];
void computePrimes(int limit = 100100) {              // #include <cassert>
    fill(isPrime, isPrime + limit + 1, true);  //最初全部trueにしておく
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i])
            for (int j = 2 * i; j <= limit; j += i) isPrime[j] = false;
}

int main() {
    int n;
    cin >> n;
    computePrimes();
    for (int i=n; ; i++) {
        if (isPrime[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}