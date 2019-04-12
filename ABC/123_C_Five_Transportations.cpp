#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long n, a, b, c, d, e;
    scanf("%ld\n%ld\n%ld\n%ld\n%ld\n%ld", &n, &a, &b, &c, &d, &e);
    long slow = min({a, b, c, d, e});
    printf("%ld\n", 5+(n-1)/slow);
    return 0;
}