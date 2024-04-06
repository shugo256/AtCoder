#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

template <typename dist_t>
class Tree {
    using edge_t = pair<dist_t, int>;

    int n; // number of nodes
    vector<edge_t> *G;
    bool *visited;

public:
    Tree() = default;
    Tree(int _n) : n(_n), G(new vector<edge_t>[(size_t)_n]), visited(new bool[(size_t)_n]) {
        fill(visited, visited+n, false);
    }

    inline void add_edge(int from, int to, dist_t dist=1) {
        G[from].push_back(edge_t{dist, to});
    }

    inline bool has_visited(int i) { return visited[i]; }
    inline void set_visited(int i) { visited[i] = true;}

    vector<edge_t> &operator[](int i) { return G[i]; }
    const vector<edge_t> &operator[](int i) const { return G[i]; }
};

ll dfs(int i, Tree<int> &tree, vector<ll> &cnt, vector<int> &color, vector<ll> &ans) {
    ll subtree_size  = 1, clean_sum = 0;
    tree.set_visited(i);
    for (auto &next:tree[i]) {
        if (tree.has_visited(next.second)) continue;
        tree.set_visited(next.second);
        ll before = cnt[color[i]];
        ll child_size = dfs(next.second, tree, cnt, color, ans);
        ll after = cnt[color[i]];
        subtree_size += child_size;
        ll clean = child_size - (before - after);
        ans[color[i]] += clean * (clean + 1) / 2;
        clean_sum += clean;
    }
    cnt[color[i]] -= clean_sum + 1;
    return subtree_size;
}

int main() {
    int n;
    cin >> n;
    vector<int> color(n);
    for (auto &ci:color) {
        cin >> ci;
        ci--;
    }
    Tree<int> t(n);
    for (int i=0, ai, bi; i<n-1; i++) {
        cin >> ai >> bi;
        t.add_edge(--ai, --bi);
        t.add_edge(bi, ai);
    }
    vector<ll> ans(n, 0);
    vector<ll> cnt(n, n);
    dfs(0, t, cnt, color, ans);
    ll total = (ll)n * (n+1) / 2;
    for (int i=0; i<n; i++) {
        ans[i] += cnt[i] * (cnt[i] + 1) / 2;
        cout << total - ans[i] << '\n';
    }
    return 0;
}