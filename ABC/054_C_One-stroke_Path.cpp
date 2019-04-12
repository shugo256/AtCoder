#include <cstdio>
#include <algorithm>

#define MAX_N 8

using namespace std;

int main() {
    int N,M,a,b,i,sum=0;
    scanf("%d %d",&N,&M);
    int perm[N];
    bool path[MAX_N][MAX_N] = {{0}};
    for (i=0; i<N; i++)
        perm[i] = i;
    for (i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        path[a-1][b-1] = true;
        path[b-1][a-1] = true;
    }
    do {
        for (i=0; i<N-1 && path[perm[i]][perm[i+1]]; i++);
        if (i == N-1) sum++;
    } while (next_permutation(perm+1,perm+N));
    printf("%d\n",sum);
    return 0;
}