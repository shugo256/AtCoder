#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, K, i, min=1000000000;
    scanf("%d %d",&N,&K);
    int h[N];
    for (i=0; i<N; i++) {
        scanf("%d",&h[i]);
    }
    sort(h,h+N);
    for (i=0; i<=N-K; i++) {
        if (h[i+K-1]-h[i] < min) {
            min = h[i+K-1]-h[i];
        }
    } 
    printf("%d\n",min);
}