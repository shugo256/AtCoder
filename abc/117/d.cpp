#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<bool, int> P;

#define MAX_LOGK 50

int N;
ll K;
bool Kbits[MAX_LOGK] = {0};
P best[MAX_LOGK];

//limitはKbitsに張り付いているかどうか
ll dfs(int i, ll digit, bool limit, ll total) {
    if (digit == 1) {
        return total;
    } else {
        i--; digit /= 2;
        ll a = total + best[i].second * digit;
        ll b = total + (N - best[i].second) * digit;
        if (!limit || (!best[i].first && Kbits[i]))
            return dfs(i, digit, false, a);
        else if (Kbits[i])
            return max(dfs(i, digit, true, a), dfs(i, digit, false, b));
        else
            return dfs(i, digit, true, best[i].first ? b : a);
    }
}

int main() {
    scanf("%d %lld", &N, &K);
    ll A[N];
    for (int i=0; i<N; i++) {
        scanf("%lld", &A[i]);
    }
    int sum;
    ll digit = 1;
    for (int i=0; i<MAX_LOGK; i++) {
        sum = 0;
        for (int j=0; j<N; j++) {
            sum += A[j]%2;
            A[j] /= 2;
        }
        best[i].first = (2*sum < N);
        best[i].second = max(sum, N - sum);
        Kbits[i] = K%2;
        K /= 2;
        digit *= 2;
    }
    printf("%lld\n", dfs(MAX_LOGK, digit, true, 0));
    return 0;
}