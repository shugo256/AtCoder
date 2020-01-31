#include <cstdio>
#include <algorithm>

using namespace std;

int up(int n) {
    return ((n-1)/10+1)*10;
}

int main() {
    int a, b, c, d, e;
    scanf("%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &e);
    printf("%d\n", up(a)+up(b)+up(c)+up(d)+up(e)-max({up(a)-a,up(b)-b,up(c)-c,up(d)-d,up(e)-e}));
    return 0;
}