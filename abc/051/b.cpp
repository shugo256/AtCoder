#include <cstdio>

int main() {
    int K,S,X,Y,count=0;
    scanf("%d %d",&K,&S);
    for (X=0; X<=K && X<=S; X++) {
        for (Y=0; Y<=K && Y<=S-X; Y++) {
            if (S-X-Y <= K) count++;
        }
    }
    printf("%d\n",count);
    return 0;
}