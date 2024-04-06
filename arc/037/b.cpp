#include <cstdio>
#include <cstring>

#define MAX_N 100

int N,M;
bool relation[MAX_N][MAX_N] = {{0}};

bool dfs(int n, bool graph[]) {
    int count=0,i;
    graph[n] = true;
    for (i=0; i<N; i++) {
        if (!relation[n][i]) 
            continue;
        if (graph[i])
            count++;
        else if (!dfs(i,graph))
            return false;
        if (count >= 2) 
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d",&N,&M);
    int i,j,ui,vi,trees=0;
    bool graph[MAX_N] = {0}, checked[MAX_N] = {0};
    for (i=0; i<M; i++) {
        scanf("%d %d",&ui,&vi);
        relation[ui-1][vi-1] = true;
        relation[vi-1][ui-1] = true;
    }
    for (i=0; i<N; i++) {
        if (checked[i]) continue;
        if (dfs(i,graph)) trees++;
        for (j=0; j<N; j++) {
            if (graph[j]) checked[j] = true;
            graph[j] = false;
        }
    }
    printf("%d\n",trees);
    return 0;
}