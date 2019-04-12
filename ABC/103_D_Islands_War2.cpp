#include <cstdio>
#include <algorithm>

//解説をちゃんと読んで橋を数える部分の計算量を O(N^2)->O(N)に。
//ソートがあるので合計はO(NlogN) 591ms->26ms!!!

using namespace std;

struct war
{
    int a;
    int b;
};

bool cmp(const war& left, const war& right) {
    return left.b < right.b;
}

int main () {
    int N,M,a,b,sum=0,bridge=-1,i;//bridgeは最後に消した橋
    scanf("%d %d",&N,&M);
    war wars[M];
    for (i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        wars[i] = war{a,b};
    }
    sort(wars,wars+M,cmp);
    for (i=0; i<M; i++) {
        if (wars[i].a > bridge) {
            bridge = wars[i].b-1;
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}