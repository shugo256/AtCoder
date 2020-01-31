#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define INF 100000

using namespace std;

int N, A, B, C, l[8];

int dfs(int i, int mp, int a, int b, int c) {
    if (i == N) return (a>0 && b>0 && c>0) ? mp + abs(A-a) + abs(B-b) + abs(C-c) : INF;
    int mpa = dfs(i+1, mp+(a>0 ? 10 : 0), a+l[i], b, c),
        mpb = dfs(i+1, mp+(b>0 ? 10 : 0), a, b+l[i], c),
        mpc = dfs(i+1, mp+(c>0 ? 10 : 0), a, b, c+l[i]),
        mp_ = dfs(i+1, mp, a, b, c);
    return min({mpa, mpb, mpc, mp_});
}

int main() {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    for (int i=0; i<N; i++)
        scanf("%d", l+i);
    printf("%d\n", dfs(0, 0, 0, 0, 0));
    return 0;
}