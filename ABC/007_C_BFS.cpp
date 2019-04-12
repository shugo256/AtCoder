#include <cstdio>
#include <queue>

#define MAX_R 50
#define MAX_C 50

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

int main () {
    point p, g, pn;
    int R, C, i;
    int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    scanf("%d %d\n%d %d\n%d %d",&R,&C,&p.x,&p.y,&g.x,&g.y);
    p.x--; p.y--; g.x--; g.y--;
    char map[R][C+1];
    int d[R][C];
    for (i=0; i<R; i++) {
        scanf("%s",map[i]);
    }
    queue<point> Q;
    map[p.x][p.y] = '#';
    d[p.x][p.y] = 0;
    Q.push(p);
    while (Q.size() != 0) {
        p = Q.front(); Q.pop();
        if (p == g) break;
        for (i=0; i<4; i++) {
            pn = p + next[i];
            if (map[pn.x][pn.y] != '#') {
                map[pn.x][pn.y] = '#';
                d[pn.x][pn.y] = d[p.x][p.y] + 1;
                Q.push(pn);
            }
        }
    }
    printf("%d\n",d[p.x][p.y]);
    return 0;
}