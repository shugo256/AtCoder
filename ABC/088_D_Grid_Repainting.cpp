#include <cstdio>
#include <queue>

using namespace std;
struct point {
    int x;
    int y;
};

struct point operator + (const point& p, const int dp[2]) {
    point result;
    result.x = p.x+dp[0]; result.y = p.y+dp[1];
    return result;
}

bool operator == (const point& p, const point& q) {
    return p.x == q.x && p.y == q.y;
}

bool operator <= (const point& p, const point& q) {
    return p.x <= q.x && p.y <= q.y;
}

int main () {
    point p, g, pn, min;
    int H, W, i, j, black=0;
    int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    scanf("%d %d",&H,&W);
    p.x = 0  ; p.y = 0;
    g.x = H-1; g.y = W-1;
    min.x = 0; min.y = 0;
    char map[H][W+1];
    int d[H][W];
    for (i=0; i<H; i++) {
        scanf("%s",map[i]);
        for (j=0; j<W; j++) 
            if (map[i][j] == '#') black++;
    }
    queue<point> Q;
    map[p.x][p.y] = '#';
    d[p.x][p.y] = 0;
    d[g.x][g.y] = 0;
    Q.push(p);
    while (Q.size() != 0) {
        p = Q.front(); Q.pop();
        if (p == g) break;
        for (i=0; i<4; i++) {
            pn = p + next[i];
            if (min <= pn && pn <= g && map[pn.x][pn.y] != '#') {
                map[pn.x][pn.y] = '#';
                d[pn.x][pn.y] = d[p.x][p.y] + 1;
                Q.push(pn);
            }
        }
    }
    printf("%d\n", (d[g.x][g.y]==0) ? -1 : H*W-black-d[g.x][g.y]-1 );
    return 0;
}