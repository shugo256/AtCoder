#include <cstdio>

int main() {
    int N, H, W, A, B, count=0;
    scanf("%d %d %d", &N, &H, &W);
    for (int i=0; i<N; i++) {
        scanf("%d %d",&A,&B);
        if (A >= H && B >= W) count++;
    }
    printf("%d\n", count);
    return 0;
}