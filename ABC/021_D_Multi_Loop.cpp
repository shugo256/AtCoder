#include <cstdio>

#define mod (int)(1e9+7)

long fact(int k) {
    if (k == 0) return 1;
    else return k * fact(k-1) % mod;
}

long mypow(long k, int p) {
    if (p == 0) return 1;
    else {
        long a = mypow(k, p/2), b = a * a % mod;
        return b * (p % 2 ? k : 1) % mod;
    }
}

int main() {
    int n, k;
    scanf("%d\n%d", &n, &k);
    long inv = mypow(fact(k), mod-2);
    long ans = 1;
    for (int i=k; i>=1; i--)
        ans = ans * (n+i-1) % mod;
    printf("%ld\n", ans * inv % mod);
    return 0;
}