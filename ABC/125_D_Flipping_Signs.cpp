#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long n, sum=0, a, minabs=(int)1e9, count=0;
    scanf("%ld", &n);
    for (int i=0; i<n; i++) {
        scanf("%ld", &a);
        sum += abs(a);
        if (a < 0)
            count++;
        minabs = min(minabs, abs(a));
    }
    printf("%ld\n", sum - (count%2 ? 2*minabs : 0));
    return 0;
}