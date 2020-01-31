#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int,int> P;

int main() {
    int N;
    scanf("%d", &N);
    vector<P> primes;
    bool isprime;
    for (int i=2; i<=N; i++) {
        int n = i;
        isprime = true;
        for (size_t j=0; j<primes.size(); j++) {
            while (n % primes[j].first == 0) {
                if (isprime) isprime = false;
                primes[j].second++;
                n /= primes[j].first;
            }
            if (n == 1) break;
        }
        if (isprime) primes.push_back({i, 2});
    }
    int num3=0, num5=0, num15=0, num25=0, num75=0;
    for (size_t j=0; j<primes.size(); j++) {
        if (primes[j].second >= 75) num75++;
        if (primes[j].second >= 25) num25++;
        if (primes[j].second >= 15) num15++;
        if (primes[j].second >= 5) num5++;
        if (primes[j].second >= 3) num3++;
    }
    printf("%d\n", num5*(num5-1)*(num3-2)/2 + num25*(num3-1) + num15*(num5-1) + num75);
    return 0;
}