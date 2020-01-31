#include <cstdio>
#include <algorithm>

#define ALPHA_NUM 26

using namespace std;

int alpha_count[ALPHA_NUM] = {0};

int mismatch(int len, char s[]) {
    int scount=0,sum=0;
    for (char c='a'; c<='z'; c++) {
        scount = 0;
        for (int j=0; j<len; j++)
            if (s[j] == c) scount++;
        sum += min(scount,alpha_count[c-'a']);
    }
    return len - sum;
}

int main() {
    int N,K,i,j;
    scanf("%d %d",&N,&K);
    char S[N+1],T[N+1];
    T[N] = '\0';
    scanf("%s",S);
    for (i=0; i<N; i++) {
        alpha_count[S[i]-'a']++;
    }
    for (i=0; i<N; i++) {
        for (j=0; j<ALPHA_NUM; j++) {
            if (alpha_count[j]>0) {
                alpha_count[j]--;
                if (S[i] - 'a' == j && mismatch(N-i-1,S+i+1) <= K) {
                    T[i] = S[i]; 
                    break;
                } else if (mismatch(N-i-1,S+i+1) < K) {
                    T[i] = 'a' + (char)j;
                    K--;
                    break;
                }
                alpha_count[j]++;
            }
        }
    }
    printf("%s\n",T);
    return 0;
}