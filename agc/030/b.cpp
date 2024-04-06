#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

ll burning_tree(ll X[], int N, ll L) {
    int i, lap=N;
    ll sum = 0;
    for (i=0; i<=N; i++) {
        sum += ( (i<N ? X[i] : L) - (i>0 ? X[i-1] : 0) ) * lap;
        if (i < N/2) lap -= 2;
        else if (i == N/2) lap = !lap; //1->0, 0->1
        else lap += 2;
    }
    ll ans = sum;
    for (i=0; i<N-1; i++) { //iは切り返す位置-1
        int last = i + (N-i+1)/2; //終着点のidx
        int last_next = i + (N-i)/2; //次のiについての終着点のidx-1
        sum += X[last] - X[i];
        sum -= L - (X[last_next] - X[i]);
        ans = max(ans,sum);
    }
    return ans;
}

int main() {
    int N, i;
    ll L;
    scanf("%lld %d",&L,&N);
    ll X[N];
    for (i=0; i<N; i++) scanf("%lld",&X[i]);
    ll ans = burning_tree(X,N,L);
    reverse(X,X+N);
    for (i=0; i<N; i++) X[i] = L-X[i];
    printf("%lld\n",max(ans,burning_tree(X,N,L)));
    return 0;
}