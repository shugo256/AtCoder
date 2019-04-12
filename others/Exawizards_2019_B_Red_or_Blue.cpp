#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, count=0;
    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++) {
        int c = getchar();
        if (c == 'R') count++;
        else count--;
    }
    printf("%s\n", (count>0) ? "Yes" : "No");
    return 0;
}