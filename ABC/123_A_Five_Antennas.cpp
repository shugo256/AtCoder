#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, e, k;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k);
    printf("%s\n", k >= e-a ? "Yay!" : ":(");
    return 0;
}