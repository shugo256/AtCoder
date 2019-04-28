#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, sum=0;
    scanf("%d", &n);
    int v[n], c;
    for (int i=0; i<n; i++) scanf("%d", v+i);
    for (int i=0; i<n; i++) {
        scanf("%d", &c);
        sum += max(0, v[i] - c);
    }
    printf("%d\n", sum);
    return 0;
}