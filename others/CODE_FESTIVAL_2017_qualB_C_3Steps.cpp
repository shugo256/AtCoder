#include <cstdio>
#include <vector>

#define MAX_N 100000

using namespace std;

vector<int> G[MAX_N];
int color[MAX_N] = {0};
int each[2] = {0}; //各色のノードが何個ずつあるか

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
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &A, &B);
        G[A-1].push_back(B-1);
        G[B-1].push_back(A-1);
    }
    printf("%ld\n", (dfs(0,1) ? (long)each[0]*each[1] : (long)N*(N-1)/2) - M);
    return 0;
}