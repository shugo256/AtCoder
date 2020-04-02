#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>

using ll = long long;

using namespace std;

struct grid{ int x, y, d; };

int h, w;
int board[101][101];
bool visited[101][101];

int main() {
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        string s; cin >> s;
        for (int j=0; j<w; j++) {
            board[i][j] = (s[j] == '#');
        }
    }
    fill(visited[0], visited[h], false);

    deque<grid> q;
    q.push_front({0, 0, board[0][0] + board[h-1][w-1]});
    while (true) {
        grid f = q.front(); q.pop_front();

        if (f.x == h-1 && f.y == w-1) {
            cout << f.d / 2 << '\n';
            return 0;
        }
        if (f.x < h-1 && !visited[f.x+1][f.y]) {
            visited[f.x+1][f.y] = true;
            if (board[f.x+1][f.y] == board[f.x][f.y])
                q.push_front({f.x+1, f.y, f.d});
            else 
                q.push_back({f.x+1, f.y, f.d+1});
        }
        if (f.y < w-1 && !visited[f.x][f.y+1]) {
            visited[f.x+1][f.y] = true;
            if (board[f.x][f.y+1] == board[f.x][f.y])
                q.push_front({f.x, f.y+1, f.d});
            else 
                q.push_back({f.x, f.y+1, f.d+1});
        }
    }
    return 0;
}