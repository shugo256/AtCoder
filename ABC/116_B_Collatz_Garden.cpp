#include <cstdio>
#include <algorithm>

int f(int n) {
    if (n%2 == 0) {
        return n/2;
    } else {
        return 3*n+1;
    }
}

int main() {
    int a[1000000], i;
    scanf("%d", &a[0]);
    for (i=1; i<1000000; i++) {
        a[i] = f(a[i-1]);
        auto result = std::find(a, a+i, a[i]);
        if (result != a+i) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    return 1;
}