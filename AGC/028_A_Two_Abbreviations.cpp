#include <cstdio>

using namespace std;

typedef long long ll;

ll lcm(ll N, ll M) {
    if (N<M) return lcm(M,N);
    ll product=N*M, buf;
    while(M != 0) {
        buf = N;
        N = M;
        M = buf%M;
    }
    return product/N;
}

int main() {
    int i,j=0,k=0;
    ll N,M,L,jump;
    scanf("%lld %lld",&N,&M);
    char S[N+1],T[M+1];
    scanf("%s",S);
    scanf("%s",T);
    L = lcm(N,M);
    N = L/N; M = L/M;
    jump = lcm(N,M);
    for (i=0; i<L/jump; i++) {
        if (S[j] != T[k]) {
            printf("-1\n");
            return 0;
        }
        j += jump/N;
        k += jump/M;
    }
    printf("%lld\n",L);
    return 0;
}
