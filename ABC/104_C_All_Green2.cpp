#include <cstdio>
#include <algorithm>
using namespace std;

//解説を参考に改良

int D,G;

int dfs(int i, int sum, int solved, int p[], int c[], bool completed[]) {
    if (sum >= G) {
        return solved;
    } else if (i == 0) {
        int max_i=D;
        while (completed[max_i-=1] && max_i >= 0);
        if (max_i >= 0 && sum + 100*(max_i+1)*(p[max_i]-1) >= G) 
            return solved + (G-sum+(100*(max_i+1)-1))/(100*(max_i+1));
        else 
            return 1000;
    } else {
        i--;
        completed[i] = true;
        int a = dfs(i, sum+100*(i+1)*p[i]+c[i], solved+p[i], p, c, completed);
        completed[i] = false;
        return min(a,dfs(i, sum, solved, p, c, completed));
    }
}

int main() {
    scanf("%d %d",&D,&G);
    int p[D],c[D];
    bool completed[D];
    for (int i=0; i<D; i++) {
        scanf("%d %d",&p[i],&c[i]);
        completed[i] = false;
    }
    printf("%d\n",dfs(D,0,0,p,c,completed));
}