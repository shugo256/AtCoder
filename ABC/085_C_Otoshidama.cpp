#include <cstdio>

int main() {
    int N,Y;
    scanf("%d %d",&N,&Y);
    int n=N,y=Y,honto=0;
    int i,j,k;
    for (i=0; i <= n && i <= y/10000; i++) { //まず10000円札の枚数決める
        n -= i; y -= 10000*i;
        for (j=0; j <= n && j <= y/5000; j++) {
            n -= j; y -= 5000*j;
            if (y == 1000*n) {
                honto = 1;
                k = n;
                break;
            }
            n += j; y += 5000*j;
        }
        if (honto) {
            break;
        }
        n = N; y = Y;
    }
    if (honto) {
        printf("%d %d %d\n",i,j,k);
    } else {
        printf("-1 -1 -1\n");
    }
}