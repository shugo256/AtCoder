#include <cstdio>

#define MAX 100

//14行目のifのなかみの順番入れ替えただけで実行時間が2ms->1msに

int A[MAX], B[MAX];

int main() {
    int T, N, M, i, j=0;
    scanf("%d\n%d",&T,&N);
    for (i=0; i<N; i++) scanf("%d",&A[i]);
    scanf("%d",&M);
    for (i=0; i<M; i++) scanf("%d",&B[i]);
    for (i=0; i<N; i++) {
        if (A[i] > B[j] || N-i < M-j) break;//残りのたこ焼きよりお客さんの方が多いor次の客に間に合わない時
        if (B[j] <= A[i]+T) j++;
        if (j == M) { //全員捌ききる
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}