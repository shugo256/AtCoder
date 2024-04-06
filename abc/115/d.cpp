#include <cstdio>

//初参加 満点！！！！！！！！！！！！！！！！

long pow_2(int N) {
    if (N == 0) {
        return 1;
    } else {
        long M = pow_2(N/2);
        M *= M;
        if (N % 2 == 1) {
            M *= 2;
        }
        return M;
    }
}

long count_patty(int N, long X, long X_max, long P_max) {
    if (N == 0 && X == 1) {
        return 1;
    } else if (X <= N) {
        return 0;
    } else if (X >= X_max-N) {
        return P_max;
    } else {
        long P;
        X_max = (X_max-3)/2;
        P_max = (P_max-1)/2;
        if (X <= X_max+1) {
            P = count_patty(N-1,X-1,X_max,P_max);
        } else {
            P = P_max + 1 + count_patty(N-1,X-X_max-2,X_max,P_max);
        }
        return P;
    }
}
int main() {
    int N;
    long X,X_max,P_max;
    scanf("%d %ld",&N,&X);
    X_max = pow_2(N+2) - 3;
    P_max = pow_2(N+1) - 1;
    printf("%ld\n",count_patty(N,X,X_max,P_max));
}