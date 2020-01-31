#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int c, count = 0, ans = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == 'A' || c == 'G' || c == 'C' || c == 'T') count++;
        else count = 0;
        ans = max(ans, count);
    }
    printf("%d\n", ans);
    return 0;
}