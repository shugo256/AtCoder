#include <cstdio>

int main() {
    long A,B,C;
    scanf("%ld %ld %ld",&A,&B,&C);
    if (A+B < C) {
        printf("%ld\n",A+B+1+B);
    } else {
        printf("%ld\n",B+C);
    }
}