#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 100010

using namespace std;

typedef pair<int,int> P;

int main() {
    int n, c;
    cin >> n >> c;
    vector<P> G[c];
    for (int i=0; i<n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        G[c-1].push_back({s, t});
    }
    int total[MAX] = {0};
    for (auto &row:G) {
        int chan[MAX] = {0};
        for (auto p:row)
            for (int i=p.first; i<=p.second; i++) 
                chan[i] = 1;
        for (int i=0; i<MAX; i++) 
            total[i] += chan[i];
    }
    int x = 0;
    for (auto t:total) x = max(x, t);
    cout << x << '\n';
    return 0;
}