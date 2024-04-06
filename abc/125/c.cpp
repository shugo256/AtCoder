#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        int buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b%a);
}

int main() {
    int n;
    scanf("%d", &n);
    int front[n+1], back[n+1], a[n];
    for (int i=0; i<n; i++) scanf("%d", a+i);
    front[0] = 0; back[n] = 0;
    for (int i=0; i<n; i++) {
        front[i+1] = gcd(front[i], a[i]);
        back[n-1-i] = gcd(back[n-i], a[n-1-i]);
    }
    int ans=0;
    for (int i=0; i<n; i++) ans = max(ans, gcd(front[i], back[i+1]));
    printf("%d\n", ans);
    return 0;
}