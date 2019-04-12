#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 200000

typedef long long ll;

ll pow2(int n) {
    if (n == 0) return 1;
    else {
        ll x = pow2(n/2);
        if (n%2 == 0) return x*x;
        else return x*x*2;
    }
}

int main() {
    int N, i=0, j=0, mid, match=0;
    bool used[MAX_N] = {0};
    ll target=pow2(30);
    scanf("%d",&N);
    ll A[N];
    for (i=0; i<N; i++) {
        scanf("%lld",&A[i]);
    }
    sort(A,A+N,greater<ll>());
    while (target > 1) {
        target/=2;
        if (A[j] < target) continue;
        for ( ; A[j]>target && j < N; j++) {
            if (used[j]) continue;
            long low = lower_bound(A+mid,A+N,2*target-A[j],greater<ll>()) - A;
            long up = upper_bound(A+mid,A+N,2*target-A[j],greater<ll>()) - A;
            for ( ; (used[low] || low == j) && low < up; low++);
            if (low == up) continue;
            match++;
            used[j] = true; used[low] = true;
        }
        mid = 0;
        for ( ; A[j] == target; j++) if (!used[j]) mid++;
        match += mid/2;
        i = j;
    }
    printf("%d\n",match);
}