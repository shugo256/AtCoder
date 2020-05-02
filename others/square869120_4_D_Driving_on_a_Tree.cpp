#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

#include <functional>

template <typename data_t>
class RerootingTree {

    struct edge {
        int to;      // dest node
        int rev;     // index of reverse edge
        data_t data;
    };

    /* merge_data_func
     *   merge two datas
     * \in : data_t a, data_t b
     * \out : data_t (merge of a and b)
     */
    using merge_data_func = function<data_t(data_t, data_t)>;

    /* add_root_func
     *   merge a data and a node
     * \in : 
     *   data_t a : sum of the data towards all child subtrees
     *     // (erased)int root : root of the current subtree
     *   data_t from_par : original data that was on edge(root<-par)
     * \out : data_t (complete data of the current subtree)
     */
    using add_root_func = function<data_t(data_t, data_t)>;

    int n;                            // number of edges
    vector<vector<edge>> G;           // G[i] : list of edges starts from node_i
    const merge_data_func merge_data;
    const add_root_func  add_root;
    const data_t identity;            // identity of data_t (if integer, its 0)

    vector<data_t> result;

public:

    RerootingTree(int _n, merge_data_func _merge_data, add_root_func _add_root, data_t _identity) 
        : n(_n)
        , G((size_t)n, vector<edge>())
        , merge_data(_merge_data)
        , add_root(_add_root)
        , identity(_identity)
        , result((size_t)n) {}

    // add edge a <-> b
    void add_edge(int a, int b, data_t data) {
        int arev = (int)G[(size_t)b].size(), brev = (int)G[(size_t)a].size();
        G[(size_t)a].push_back({b, arev, data});
        G[(size_t)b].push_back({a, brev, data});
    }
    void add_edge(int a, int b) { add_edge(a, b, identity); }

    // the main function
    vector<data_t> operator()() {
        dfs_from_root(0, -1, identity);
        dfs_to_root(0, -1, identity);
        return result;
    }

    // get the structure of the tree
    auto operator[](int i) const { return G.at(i); }
    auto &operator[](int i) { return G.at(i); }

    auto begin() { return G.begin(); }
    auto end()   { return G.end(); }

private:
    // determines all data of edges which directs towards the botom of the tree
    data_t dfs_from_root(int node, int par, data_t data_from_par) {
        auto &edges = G[(size_t)node];
        data_t result = identity;
        for (auto &e:edges) {
            if (e.to == par) continue;
            e.data = dfs_from_root(e.to, node, e.data);
            result = merge_data(result, e.data);
        }
        return add_root(result, data_from_par);
    }

    // determines all data of edges which directs towards the root
    void dfs_to_root(int node, int par, data_t data_to_par) {
        auto &edges = G[(size_t)node];
        size_t deg = edges.size();
        vector<data_t> cumul_l(deg+1, identity), cumul_r(deg+1, identity); // cumulative sum of data from both sides
        for (size_t i=0; i<deg; i++) {
            if (edges[i].to == par) {
                edges[i].data = data_to_par;
            }
            cumul_l[i+1] = merge_data(cumul_l[i], edges[i].data);
        }
        for (size_t i=deg; i>0; i--) {
            cumul_r[i-1] = merge_data(cumul_r[i], edges[i-1].data);
        }

        result[(size_t)node] = add_root(cumul_r[0], identity); // sum of all Datas is the result for the node

        for (size_t i=0; i<deg; i++) {
            if (edges[i].to == par) continue;
            data_t total_of_others = merge_data(cumul_l[i], cumul_r[i+1]);
            data_t rev_edge_data = G[(size_t)edges[i].to][(size_t)edges[i].rev].data;
            dfs_to_root(edges[i].to, node, add_root(total_of_others, rev_edge_data));
        }
    }
};
/*
Constructers
RerootingTree(n, merge_data, add_root, identity)
*/

using P = pair<double, int>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    int deg[n];
    fill(deg, deg+n, 0);
    RerootingTree<P> rrt(
        n,
        [](P a, P b) { return P{a.fi + b.fi, a.se + b.se}; },
        [](P a, P par) { 
            if (a.se > 0)
                return P{a.fi / a.se + 1, 1}; 
            else
                return P{a.fi, 1};
        },
        P{0, 0}
    );
    for (int i=0, ui, vi; i<n-1; i++) {
        cin >> ui >> vi;
        rrt.add_edge(--ui, --vi);
        deg[ui]++;
        deg[vi]++;
    }
    for (auto &ri:rrt()) cout << setprecision(15) << fixed << ri.fi << endl;
    for (int i=0; i<n; i++) {
        for (auto &g:rrt[i]) {
            cerr << i << ' ' << g.to << ' ' << g.data.fi << ' ' << g.data.se << '\n';
        }
    }
    return 0;
}