#include <cstdio>
#include <iostream>
using namespace std;

//コード長452byte 実行時間2ms メモリ256kb 
//やはり何も考えないアルゴリでは実行時間がなげえ。
int main() {
    int N,A,B,n,sum,total=0;
    scanf("%d %d %d",&N,&A,&B);
    for (int i=0; i <= N; i++) { //まず500円玉の枚数決める
        sum = 0;
        n = i;
        for (int m=10000; m>=1; m/=10) {
            sum += n/m;
            n %= m;
        }
        if (A <= sum && sum <= B) {
            total += i;
        }
    }
    printf("%d\n",total);
}