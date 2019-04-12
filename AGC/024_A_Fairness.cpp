#include <cstdio>

int main() {
    int A,B;
    long K;
    scanf("%d %d %*d %ld",&A,&B,&K);
    printf("%d\n", (K%2 == 1) ? B-A : A-B);
    return 0;
}