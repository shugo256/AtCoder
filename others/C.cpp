#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, wcount = 0, bcount = 0, bbuf = 0, pre = 0;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        int c = getchar();
        if (c == '.') {
            bcount += bbuf;
            bbuf = 0;
            if (bcount) wcount++;
            if (bcount < wcount) {
                pre += bcount;
                bcount = 0;
                wcount = 0;
            }
        } else {
            bbuf++;
        }
    }
    printf("%d\n", pre + min(bcount, wcount));
    return 0;
}