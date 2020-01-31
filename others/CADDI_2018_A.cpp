#include <cstdio>

int main() {
    int N, count=0;
    scanf("%d",&N);
    for ( ; N > 0; N /= 10) if (N % 10 == 2) count++;
    printf("%d\n",count);
    return 0;
}