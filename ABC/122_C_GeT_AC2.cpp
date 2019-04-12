#include <cstdio>
#include <algorithm>

#define MAX_N 100000

//累積和で高速化ver

using namespace std;

int main() {
    int N, Q, csum[MAX_N] = {0};
    bool a;
    scanf("%d %d", &N, &Q); getchar();
    for (int i=0; i<N; i++) {
        int c = getchar();
        if (a && c == 'C') csum[i] = csum[i-1] + 1;
        else if (i > 0) csum[i] = csum[i-1];
        if (c == 'A') a = true;
        else a = false;
    }
    for (int i=0; i<Q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", csum[r-1] - csum[l-1]);
    }
    return 0;
}