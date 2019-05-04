#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int h, w, n, x, y;
    scanf("%d %d %d\n%d %d", &h, &w, &n, &x, &y);
    char s[n+1], t[n+1];
    scanf("\n%s\n%s", s, t);
    int limits[] = {0, 0, 0, 0}; //limitsは危険区域
    char taka[] = "LRUD", ao[] = "RLDU";
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<4; j++)
            if (s[i] == taka[j])
                limits[j] += 1;
        if (limits[0] + limits[1] >= w || limits[2] + limits[3] >= h) {
            printf("NO\n");
            return 0;
        }
        if (i > 0) 
            for (int j=0; j<4; j++)
                if (t[i-1] == ao[j] && limits[j] > 0)
                    limits[j] -= 1;
    }
    if (limits[0] < y && y < w - limits[1] + 1 && limits[2] < x && x < h - limits[3] + 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}