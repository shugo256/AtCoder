#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    bool black[1000][1000];
    char s[1001];
    int x[] = {1, -1, 0,  0},
        y[] = {0,  0, 1, -1};
    queue<P> q;
    for (int i=0; i<h; i++) {
        scanf("\n%s", s);
        for (int j=0; j<w; j++) {
            black[i][j] = (s[j] == '#');
            if (black[i][j]) q.push(P(i, j));
        }
    }
    int count=0;
    q.push(P(-1,-1)); //しきり
    while (q.size() > 0) {
        P p = q.front(); q.pop();
        int i = p.first, j = p.second;
        if (q.size() > 0 && i == -1 && j == -1) {
            q.push(P(-1,-1));
            count++;
            continue;
        }
        for (int k=0; k<4; k++) {
            int i1 = i+x[k], j1 = j+y[k];
            if (0 <= i1 && i1 < h && 0 <= j1 && j1 < w && !black[i1][j1]) {
                black[i1][j1] = true;
                q.push(P(i1, j1));
            }
        }
    }
    printf("%d\n", count);
    return 0;
}