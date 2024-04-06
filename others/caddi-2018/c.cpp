#include <cstdio>
#include <cmath>

#define MAX_ROOT_P 1000000

bool primes[MAX_ROOT_P+1];

bool IsPrime(long num, long powp)
{
    if (primes[num]) {
        for (long i=2*num; i <= powp; i+=num) primes[i] = false;
    }
    return primes[num];
}

int main() {
    long N, P, gcd = 1, i;
    scanf("%ld %ld",&N,&P);
    if (N == 1) {
        printf("%ld\n", P);
        return 0;
    }
    long powp = (long)pow(P,(double)1/N);
    for (i = 2; i <= powp; i++) primes[i] = true;
    for (i = 2; i <= powp; i++) {
        if (!IsPrime(i,powp)) continue;
        long j = 0;
        for (; P % i == 0; P /= i)
            j++;
        if (j >= N)
            for (int k = 0; k < j / N; k++)
                gcd *= i;
    }
    printf("%ld\n", gcd);
    return 0;
}