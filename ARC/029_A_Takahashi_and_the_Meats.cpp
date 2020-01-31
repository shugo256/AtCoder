#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

//一発合格やで〜

int N,total=0;

int dfs(int i, int dif, int t[]) {
    if (i == N) {
        return (total + abs(dif)) / 2;
    } else {
        return min(dfs(i+1, dif+t[i], t),dfs(i+1, dif-t[i], t));
    }
}

int main() {
    scanf("%d",&N);
    int t[N];
    for (int i=0; i<N; i++) {
        scanf("%d",&t[i]);
        total += t[i];
    }
    printf("%d\n",dfs(1,t[0],t));
}