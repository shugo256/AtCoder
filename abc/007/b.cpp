#include <cstdio>
#include <cstring>

#define MAX_LEN 10

int main() {
    char A[MAX_LEN+1], n[] = "-1";
    size_t l;
    scanf("%s",A);
    if (A[0] != 'a') A[0]--;
    else if ((l=strlen(A)) > 1) A[l-1] = '\0';
    else memcpy(A,n,3);
    printf("%s\n",A);
    return 0;
}