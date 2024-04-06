#include <cstdio>

int log_2(long N) {
    //切りすて
    if (N < 2) return 0;
    else return log_2(N/2) + 1;
}

int main() {
    long X,Y;
    scanf("%ld %ld",&X,&Y);
    printf("%d\n",log_2(Y/X)+1);
}