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
    for (int i=0; i<n; i++) {
        if (g[i].size() == 1) {
            q.push(i);
        }
    }
    q.push(-1);
    int max=0, count=0;
    bool used[MAX]={0};
    while (q.size() > 0) {
        int k = q.front(); q.pop();
        if (q.size() > 0 && k == -1) {
            q.push(-1);
            max++;
            count = 0;
            continue;
        }
        for (size_t l=0; l<g[k].size(); l++) {
            if (!used[g[k][l]]) {
                used[g[k][l]] = true;
                q.push(g[k][l]);
                count++;
            }
        }
    }
    printf("%s\n", (max+count)%2 ? "First" : "Second");
    return 0;
}