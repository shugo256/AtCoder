#include <cstdio>

int main() {
    int N, p, sum=0, max=0;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d", &p);
        sum += p;
        if (p > max) max = p;
    }
    printf("%d\n",sum-max/2);
}