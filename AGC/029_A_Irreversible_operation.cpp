#include <cstdio>

typedef long long ll;

int main() {
    ll c, bcount=0, sum=0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (bcount && c == 'W') sum += bcount;
        else if (c == 'B') bcount++;
    }
    printf("%lld\n",sum);
}