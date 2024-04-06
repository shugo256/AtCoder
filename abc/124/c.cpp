#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, count = 0;
    char c;
    while ((c = (char)getchar()) == '0' || c == '1') {
        if (c - '0' == n%2) count++;
        n++;
    }
    printf("%d\n", min(count, n-count));
    return 0;
}