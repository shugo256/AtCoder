#include <cstdio>
#include <cstring>

#define MAX_LEN 50

int main() {
    char S[MAX_LEN+1], T[MAX_LEN+1];
    scanf("%s\n%s",S,T);
    int i, j, sl = (int)strlen(S), tl = (int)strlen(T);
    bool restored=false;
    for (i=sl-1; i>=0; i--) {
        if (!restored && i >= tl-1) {
            for (j=0; j<tl; j++)  {
                if (S[i-j] != '?' && S[i-j] != T[tl-j-1]) break;
            }
            if (j == tl) {
                memcpy(S+(i-tl+1),T,(size_t)tl);
                restored = true;
            } else if (S[i] == '?') S[i] = 'a';
        } else if (S[i] == '?') S[i] = 'a';
    }
    printf("%s\n", restored ? S : "UNRESTORABLE");
    return 0;
}