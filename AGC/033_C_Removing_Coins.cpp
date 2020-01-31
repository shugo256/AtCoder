#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 200100

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> g[n];
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    int d[n];
    fill(d, d+n, MAX);
    d[0] = 0;
    int k;
    while (q.size() > 0) {
        k = q.front(); q.pop();
        for (size_t l=0; l<g[k].size(); l++) {
            if (d[g[k][l]] == MAX) {
                d[g[k][l]] = d[k] + 1;
                q.push(g[k][l]);
            }
        }
    }
    q.push(k);
    fill(d, d+n, MAX);
    d[k] = 0;
    while (q.size() > 0) {
        k = q.front(); q.pop();
        for (size_t l=0; l<g[k].size(); l++) {
            if (d[g[k][l]] == MAX) {
                d[g[k][l]] = d[k] + 1;
                q.push(g[k][l]);
            }
        }
    }
    printf("%s\n", d[k]%3 != 1 ? "First" : "Second");
    return 0;
}