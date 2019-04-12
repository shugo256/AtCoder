#include <cstdio>
#include <string>

int main() {
    int N;
    scanf("%d",&N);
    char A[N+1], B[N+1], C[N+1];
    scanf("%s\n%s\n%s",A,B,C);
    int count = 0;
    for (int i=0; i<N; i++) {
        if (A[i] == B[i] && A[i] == C[i]) continue;
        if (A[i] == B[i] || A[i] == C[i] || B[i] == C[i]) count++;
        else count += 2;
    }
    printf("%d\n",count);
    return 0;
}