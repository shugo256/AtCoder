#include <cstdio>

//改良版21ms->6ms メモリ使用も13696KB->6144KBで 劇的ビフォーアフター

#define MAX_H 500
#define MAX_W 500

int H, M;
char c[MAX_H][MAX_W+1];

bool dfs(int x, int y) {
    c[x][y] = '#';
    if (y+1 < M && (c[x][y+1] == 'g' || (c[x][y+1] == '.' && dfs(x,y+1))))
        return true;
    if (0 <= y-1 && (c[x][y-1] == 'g' || (c[x][y-1] == '.' && dfs(x,y-1))))
        return true;
    if (x+1 < H && (c[x+1][y] == 'g' || (c[x+1][y] == '.' && dfs(x+1,y))))
        return true;
    if (0 <= x-1 && (c[x-1][y] == 'g' || (c[x-1][y] == '.' && dfs(x-1,y))))
        return true;
    return false;
}

int main() {
    scanf("%d %d",&H,&M);
    int i, j, x=-1, y=-1;
    for (i=0; i<H; i++) {
        scanf("%s", c[i]);
        for (j=0; j<M; j++) {
            if (c[i][j] == 's') {
                x = i; y = j;
            }
            if (x != -1) break;
        }
    }
    printf("%s\n", dfs(x, y) ? "Yes" : "No");
    return 0;
}