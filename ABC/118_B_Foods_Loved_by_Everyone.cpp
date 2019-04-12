#include <cstdio>
#include <numeric>

using namespace std;

#define MAX_M 30

int main() {
    int N, M, K, A;
    scanf("%d %d",&N,&M);
    int loved[MAX_M+1] = {0}, byall[MAX_M+1] = {0};
    for (int i=1; i<=M; i++) byall[i] = 1;
    for (int i=0; i<N; i++) {
        scanf("%d",&K);
        for (int j=0; j<K; j++) {
            scanf("%d",&A);
            loved[A] = 1;
        }
        for (int j=0; j<=M; j++) {
            if (loved[j]) loved[j] = 0;
            else byall[j] = 0;
        }
    }
    printf("%d\n", accumulate(byall+1, byall+M+1, 0));
    return 0;
}