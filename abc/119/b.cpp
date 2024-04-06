#include <cstdio>
#include <algorithm>

#define BIT 380000.0

using namespace std;

int main() {
    int N;
    double x, sum=0;
    char u[4];
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%lf %s", &x, u);
        if (u[0] == 'J') sum += x;
        else sum += BIT*x;
    }
    printf("%lf\n", sum);
    return 0;
}