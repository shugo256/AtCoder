#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    printf("%d\n", (t/a)*b);
    return 0;
}