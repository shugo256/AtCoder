#include <cstdio>
#include <algorithm>

#define MAX_N 100010

using namespace std;

int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    int j = 0, ans = 0, change[MAX_N];
    char prev = '0';
    for (int i=0; i<n; i++) {
        char c;
        scanf("%c", &c);
        if (c != prev) {
            prev = c;
            change[j] = i;
            j++;
        }
        if (c == '1')
            ans = max(i+1 - (j>=2*k+1 ? change[j-2*k-1] : 0), ans);
        else if (k > 0)
            ans = max(i+1 - (j>=2*k ? change[j-2*k] : 0), ans);
    }
    printf("%d\n", ans);
    return 0;
}


