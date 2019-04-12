#include <cstdio>

#define MAX_H 500
#define MAX_W 500

int H, M;
char c[MAX_H][MAX_W+1];

bool dfs(int x, int y) {
    c[x][y] = '#';
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i*j == 0 && 0 <= x+i && x+i < H && 0 <= y+j && y+j < M && (c[x+i][y+j] == 'g' || (c[x+i][y+j] == '.' && dfs(x+i,y+j))))
                return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d",&H,&M);
    int i, j, x, y;
    for (i=0; i<H; i++) {
        for (j=0; j<M; j++) {
            scanf(" %c", &c[i][j]);
            if (c[i][j] == 's') {
                x = i; y = j;
            }
        }
    }
    if (dfs(x,y))
        printf("Yes\n");
    else
        printf("No\n");
}