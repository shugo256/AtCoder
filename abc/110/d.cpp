#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define mod (long)(1e9+7)

using namespace std;

long C(int n, int k) {
    if (k == 0) return 1;
    else {
        long num = C(n-1, k-1) * n;
        while (num % k) num += mod;
        return (num / k) % mod;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int root = (int)sqrt(M)+1;
    vector<int> factors;
    for (int i=2; i<=root; i++) {
        if (M % i == 0) {
            int count = 0;
            for ( ; M%i==0; M/=i) count++;
            factors.push_back(count);
        }
        if (M == 1) break;
    }
    if (M > 1) factors.push_back(1);
    size_t len = factors.size();
    long result = 1;
    if (M > 1 && len == 0) result = N;
    for (size_t i=0; i<len; i++)
        result = (result * C(N+factors[i]-1, factors[i])) % mod;
    printf("%ld\n", result);
    return 0;
}