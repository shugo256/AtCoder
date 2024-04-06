#include <cstdio>
#include <deque>

#define INF 3

//01BNF 楽しいね 9msだけどかなり優秀な方

using namespace std;

struct point {
    int x;
    int y;
};

struct point operator + (const point& p, const point& q) {
    point result;
    result.x = p.x+q.x; result.y = p.y+q.y;
    return result;
}
bool operator == (const point& p, const point& q) {
    return p.x == q.x && p.y == q.y;
}
bool operator < (const point& p, const point& q) {
    return p.x < q.x || p.y < q.y;
}

int main () {
    point p, g, pn;
    int H, W, i, j;
    point next[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    scanf("%d %d",&H,&W);
    p.x = -1; g.y = -1;
    int d[H][W];
    char map[H][W+1];
    for (i=0; i<H; i++) {
        scanf("%s",map[i]);
        for (j=0; j<W; j++) {
            d[i][j] = INF;
            if (map[i][j] == 's') 
                p = point{i,j};
            else if (map[i][j] == 'g')
                g = point{i,j};
        }
    }
    deque<point> Q;
    map[p.x][p.y] = 'x';
    d[p.x][p.y] = 0;
    Q.push_back(p);
    while (Q.size() != 0) {
        p = Q.front(); Q.pop_front();
        for (i=0; i<4; i++) {
            pn = p + next[i];
            if (pn < point{0,0} || point{H-1,W-1} < pn) continue;
            if (pn == g) {
                printf("YES\n");
                return 0;
            } else if (map[pn.x][pn.y] == '.') {
                map[pn.x][pn.y] = 'x';
                d[pn.x][pn.y] = d[p.x][p.y];
                Q.push_front(pn);
            } else if (map[pn.x][pn.y] == '#' && d[p.x][p.y] < 2) {
                map[pn.x][pn.y] = 'x';
                d[pn.x][pn.y] = d[p.x][p.y] + 1;
                Q.push_back(pn);
            }
        }
    }
    printf("NO\n");
    return 0;
}