#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    printf("%s\n", y < 2019 || (y == 2019 && (m < 4 || (m == 4 && d <= 30))) ? "Heisei" : "TBD");
    return 0;
}