#include <cstdio>
#include <algorithm>

#define MAX_N 100010

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int d[q];
    char s[n+1], t[q+1]; t[q] = '\0';
    scanf("%s\n", s);
    for (int i=q-1; i>=0; i--) {
        char dc;
        scanf("\n%c %c", t+i, &dc);
        d[i] = (dc == 'R') ? 1 : -1;
    }
    int front = 0, back = 0;
    for (int i=0; i<q; i++) {
        if (front + back >= n) break;
        if (t[i] == s[front] && d[i] == -1)
            front++;
        else if (front > 0 && t[i] == s[front-1] && d[i] == 1)
            front--;
        if (t[i] == s[n-1-back] && d[i] == 1)
            back++;
        else if (back > 0 && t[i] == s[n-back] && d[i] == -1)
            back--;
    }
    printf("%d\n", max(n-front-back, 0));
    return 0;
}