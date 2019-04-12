#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 100000

using namespace std;

vector<int> G[MAX_N];
int color[MAX_N] = {0};
int each[2] = {0};
bool dfs(int n, int c) {
    color[n] = c;
    each[c == -1]++;
    size_t len = G[n].size();
    for (size_t i=0; i<len; i++) {
        int to = G[n][i];
        if (color[to] == c || (color[to] == 0 && !dfs(to, -c)))
            return false; 
    }
    return true;
}

int main() {
    int N, A, ans=0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A);
        G[i].push_back(A-1);
        G[A-1].push_back(i);
    }
    for (int i=0; i<N; i++) {
        if (color[i] != 0) continue;
        each[0] = 0; each[1] = 0;
        if (dfs(i, 1)) ans += max(each[0], each[1]);
        else {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}