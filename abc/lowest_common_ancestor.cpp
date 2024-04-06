#include <vector>

#include <cmath>
template <typename CostType=long>
using P = pair<int, CostType>;
vector<P> G[100010];
int log2i(int n) {
    int _log = 0;
    while(n >> 1) _log++;
    return _log
}
class LCA {
public:
    size_t n;
    vector<vector<int>> par;
    vector<int> depth;
    LCA(int _n, Graph _G, int root=0) : n((size_t)_n), 
                                        G(_G), 
                                        par(n, vector<int>(log2i(_n)))
                                        depth(n) {
        dfs(root);
        size_t _log = (size_t)log2i(_n);
        for (auto &pv:par) {
            for (size_t k=1; k<_log; k++) {
                if (pv[k-1] < 0) pv[k] = -1;
                else pv[k] = par[pv[k-1]][k-1];
            }
        }
    }
private:
    void dfs(int v, int p=-1, int d=0) {
        size_t _v = (size_t)v;
        par[_v][0] = p;
        depth[_v] = d;
        for (auto g:G[_v])
            if (g != v)
                dfs(g, v, d + 1);
    }
}