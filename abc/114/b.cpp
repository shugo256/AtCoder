#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char S[11];
    scanf("%s", S);
    size_t len = strlen(S);
    int row = 0, min = 1000;
    for (size_t i=0; i<len; i++) {
        row = (row * 10 + (S[i]-'0')) % 1000;
        const int dif = abs(row-753);
        if (i >= 2 && dif < min) min = dif;
    }
    printf("%d\n", min);
    return 0;
}