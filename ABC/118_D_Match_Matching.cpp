#include <cstdio>
#include <algorithm>
#include <vector>

#define INF 10000

using namespace std;

struct mn
{
    int n;
    int m;
};

bool mcomp(const mn& left, const mn& right) {
    return left.m < right.m || (left.m == right.m && left.n > right.n);
}

bool ncomp(const mn& left, const mn& right) {
    return left.n > right.n;
}

int main() {
    int N, M, a, i, j;
    int match[] = {0,2,5,5,4,5,6,3,7,6};
    scanf("%d %d",&N,&M);
    vector<mn> A;
    for (i=0; i<M; i++) {
        scanf("%d", &a);
        mn mn1 = {a, match[a]};
        A.push_back(mn1);
    }
    sort(A.begin(), A.end(), mcomp);
    int prev = A[0].m;
    for (i=1; i<M; i++) {
        if (A[i].m == prev) {
            A.erase(A.begin()+i);
            M--; i--;
        }
        else
            prev = A[i].m;
    }
    int dp[N+1];
    dp[0] = 0;
    fill(dp+1, dp+N+1, -INF);
    for (i=0; i<N; i++) {
        if (dp[i] < 0) continue;
        for (j=0; j<M; j++) {
            if (i + A[j].m <= N)
                dp[i + A[j].m] = max(dp[i + A[j].m], dp[i] + 1);
            else 
                break;
        }
    }
    sort(A.begin(), A.end(), ncomp);
    while (N > 0) {
        for (i=0; i<M; i++) {
            if ((dp[N] > 1 && dp [N - A[i].m] == dp[N] - 1) || (dp[N] == 1 && N - A[i].m == 0)) {
                printf("%d", A[i].n);
                N -= A[i].m;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}