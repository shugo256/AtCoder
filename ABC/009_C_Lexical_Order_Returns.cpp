#include <cstdio>
#include <cstring>
#include <algorithm>

//自己流で書いてみたが、全然合わない 断念,,,
using namespace std;

int main() {
    int N,K,i=0,isorted=0,j,m,dK;
    scanf("%d %d",&N,&K);
    char S[N+1],T[N+1],sorted[N+1];
    T[N] = '\0';
    scanf("%s",S);
    memcpy(sorted,S,sizeof(S));
    memcpy(T,S,sizeof(S));
    sort(sorted,sorted+N);
    while (K > 0 && i < N) {
        m = isorted;
        if (T[i] != sorted[isorted]){ 
            //入れ替えが必要な場合
            for (j=N-1; j>i; j--)
                if (T[j] == sorted[isorted]) break;
            if (j == i) {
                isorted++;
                continue;
            } else if (T[i] == S[i] && T[j] == S[j]) { 
                //両方初めて入れ替える場合->Kを2消費
                if (K >= 2) dK = 2; //dKはあとでKからどれだけ引くか
                else {
                    //K==1の時Kを1しか消費しない入れ替え方がないか探す
                    while (++m < N) { //なかった場合はm==N ->38行目で入れ替えられない
                        for (j=N-1; j>i; j--)
                            if (T[j] == sorted[m]) break;
                        if (j != i && T[j] != S[j]) {
                            dK = 1; //あった 
                            break;
                        }
                    }
                    if (m == N) {
                        i++;
                        continue; //isortedはsortedのどこまで使ったか 入れ替えられなかった時は使えてないのでisortedは増えない
                    }
                }
            } else if (T[i] == S[i] || T[j] == S[j]) {
                //片方は入れ替えたことがある場合(片方は元の位置にある)->Kを1消費
                dK = 1;
            } else {
                dK = 0;
            }
            if (T[i]>sorted[m]) {
                //入れ替え
                T[j] = T[i];
                T[i] = sorted[m];
                K -= dK;
            }
        }
        i++; isorted++;
    }
    printf("%s\n",T);
    return 0;
}