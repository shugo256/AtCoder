#include <cstdio>
#include <cstring>

char c[10][11];

bool dfs(int x, int y) {
    c[x][y] = 'x';
    if (y+1 < 10 && c[x][y+1] == 'o' && dfs(x,y+1))
        return true;
    if (0 <= y-1 && c[x][y-1] == 'o' && dfs(x,y-1))
        return true;
    if (x+1 < 10 && c[x+1][y] == 'o' && dfs(x+1,y))
        return true;
    if (0 <= x-1 && c[x-1][y] == 'o' && dfs(x-1,y))
        return true;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (c[i][j] == 'o') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int x, y;
    for (x=0; x<10; x++) {
        scanf("%s", c[x]);
    }
    char buf[10][11];
    bool around;
    memcpy(buf, c, sizeof(c));
    for (x=0; x<10; x++) {
        for (y=0; y<10; y++) {
            around = c[x][y+1] == 'o' || c[x][y-1] == 'o' || c[x+1][y] == 'o' ||c[x-1][y] == 'o';
            if (c[x][y] == 'x' && around) {
                if (dfs(x,y)) {
                    printf("YES\n");
                    return 0;
                } else {
                    memcpy(c, buf, sizeof(buf));
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}