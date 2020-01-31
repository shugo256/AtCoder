#include <cstdio>
#include <iostream>
using namespace std;

//コード長969byte 実行時間1ms メモリ256kb

int main() {
    int N,A,B,sum=0;
    scanf("%d %d %d",&N,&A,&B);
    int n,a,b;
    for (int i=0; i <= B && i <= N/10000; i++) { //まず500円玉の枚数決める
        n = N - 10000*i; a = A-i; b = B-i;
        for (int j=0; j <= b && j <= n/1000 && j <= 9; j++) {
            n -= 1000*j; a -= j; b -= j;
            for (int k=0; k <= b && k <= n/100 && k <= 9; k++) {
                n -= 100*k; a -= k; b -= k;
                for (int l=0; l <= b && l <= n/10 && l <= 9; l++){
                    n -= 10*l; a -= l; b -= l;
                    for (int m=max(a,0); m <= n && m <= 9 && m <= b; m++) {
                        sum += N - (n - m);
                    }
                    n += 10*l; a += l; b += l;
                }
                n += 100*k; a += k; b += k;
            }
            n += 1000*j; a += j; b += j;
        }
    }
    printf("%d\n",sum);
}