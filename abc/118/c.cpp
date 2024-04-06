#include <cstdio>
#include <numeric>

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
    int N, A, min;
    scanf("%d", &N);
    scanf("%d", &min);
    for (int i=1; i<N; i++) {
        scanf("%d", &A);
        min = gcd(A, min);
    }
    printf("%d\n",min);
    return 0;
}