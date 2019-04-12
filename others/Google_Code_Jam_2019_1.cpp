#include <cstdio>

int main() {
    char N[101], A[101], B[101];
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        scanf("%s\n", N);
        int j, firstb = -1;
        for (j=0; N[j]!='\0'; j++) {
            if (N[j] == '4') {
                A[j] = '2'; B[j] = '2';
                if (firstb == -1) firstb = j;
            } else {
                A[j] = N[j]; B[j] = '0';
            }
        }
        A[j] = '\0'; B[j] = '\0';
        printf("Case #%d: %s %s\n", i+1, A, B+firstb);
    }
}