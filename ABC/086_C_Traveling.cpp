#include <cstdio>
#include <cstdlib>

int main() {
    int N;
    scanf("%d",&N);
    int t[2]={0},x[2]={0},y[2]={0};
    for (int i=0; i<N; i++) {
        t[0] = t[1]; x[0] = x[1]; y[0] = y[1];
        scanf("%d %d %d",&t[1],&x[1],&y[1]);
        if ((t[1] + x[1] + y[1]) % 2 || abs(x[1]-x[0]) + abs(y[1]-y[0]) > t[1] - t[0]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}