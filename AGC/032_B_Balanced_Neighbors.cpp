#include <cstdio>

int main() {
    int N, sum;
    scanf("%d", &N);
    sum = N%2 ? N : N+1;
    printf("%d\n", (N * (N-2) + 1) / 2);
    for (int i=1; i<N; i++) {
        int pair = sum - i;
        for (int j=i+1; j<=N; j++) {
            if (j != pair) printf("%d %d\n", i, j);
        }
    }
    return 0;
}