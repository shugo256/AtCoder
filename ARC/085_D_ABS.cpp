#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int N, Z, W, a0=0, a1;
    scanf("%d %d %d", &N, &Z, &W);
    for (int i=0; i<N; i++) {
        if (i == N-2) scanf("%d", &a0);
        else scanf("%d", &a1);
    }
    printf("%d\n", max( abs(W-a1), a0>0 ? abs(a0-a1) : 0));
    return 0;
}