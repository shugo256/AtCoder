#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <cassert>
#define MAX 2000000  // 階乗をいくつまで計算するか

class modlong {
    ll val;
    static ll *invs, *facts, *finvs;

    // 階乗, 逆元, 階乗の逆元をMAXまで求める
    bool initModlong() {
        invs[1] = 
        facts[0] = facts[1] =
        finvs[0] = finvs[1] = 1;
        for (int i=2; i<=MAX; i++) {
            invs[i]  = -invs[MOD % i] * (MOD / i) % MOD;
            facts[i] = facts[i - 1] * i % MOD;
            finvs[i] = finvs[i - 1] * invs[i] % MOD;
        }
        return true;
    }

public:
    static ll MOD; // modの元

    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(ll init = 0) : val(init) {
        static bool call_once = initModlong(); // static変数の性質により一度だけ呼ばれる
        assert(call_once); // unusedの回避
        if (val < 0 || val >= MOD) val %= MOD;
        if (val < 0) val += MOD;   // 0以上であることを保証
    }

    // llへのキャスト operator ll()で定義すると modlong +
    // llとかができなくなる
    inline ll toll() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const ll &r) { *this = modlong(r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        ll ans = this->val + r.val;
        if (ans >= MOD) ans -= MOD;
        return modlong(ans);
    }
    modlong operator-() {
        ll ans = MOD - this->val;
        return modlong(ans);
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        ll ans = this->val * r.val;
        return modlong(ans);
    }
    modlong inv() {
        assert(*this != 0);
        if (*this == 1) return modlong(1);

        modlong p, q = *this, m(0), n(1), r, c;
        p.val = MOD;  // p=modとかくとp.val=mod%mod=0となってしまう
        while (q > MAX) {
            r = p.val % q.val;  // r.val=p.val % q.val
                                // とかくよりもこのほうが代入時に%modされるので安全
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n * invs[q.val];
    }
    modlong operator/(const modlong &r) { return *this * modlong(r).inv(); }
    modlong operator%(const modlong &r) { return modlong(this->val % r.val); }

    // ++ -- 前付きと後ろ付き
    void operator++() { ++this->val; }
    void operator++(int a) {
        a = 0;
        this->val++;
    }  // a使ってなくねっていうwarningをsilenceするためにaをいじってる
    void operator--() { --this->val; }
    void operator--(int a) {
        a = 0;
        this->val--;
    }

    // 四則演算&代入
    void operator+=(const modlong &r) { *this = *this + r; }
    void operator-=(const modlong &r) { *this = *this - r; }
    void operator*=(const modlong &r) { *this = *this * r; }
    void operator/=(const modlong &r) { *this = *this / r; }
    void operator%=(const modlong &r) { *this = *this % r; }

    // べき乗
    modlong pow(long n) {
        if (n < 0)
            return inv().pow(-n);  // 逆元の-n乗
        else if (n == 0)
            return modlong(1);

        modlong half = pow(n / 2);
        if (n % 2)
            return *this * half * half;
        else
            return half * half;
    }
    modlong pow(modlong n) { return pow(n.val); }

    // コンビネーション
    modlong comb(modlong _k) {
        assert(this->val <= MAX);
        const ll n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return modlong(facts[n]) * finvs[k] * finvs[n - k];
    }

    // 階乗
    modlong fact() { 
        assert(this->val <= MAX);
        return modlong(facts[this->val]);
    }

    friend bool operator<(const modlong &l, const modlong &r) { return l.val < r.val; }
    friend bool operator>(const modlong &l, const modlong &r) { return l.val > r.val; }
    friend bool operator==(const modlong &l, const modlong &r) { return l.val == r.val; }
    friend bool operator!=(const modlong &l, const modlong &r) { return !(l == r); }
    friend bool operator<=(const modlong &l, const modlong &r) { return !(l > r); }
    friend bool operator>=(const modlong &l, const modlong &r) { return !(l < r); }

    friend ostream &operator<<(ostream &os, const modlong &out) {
        os << out.val;
        return os;
    }
    friend istream &operator>>(istream &is, modlong &in) {
        ll inl;
        is >> inl;
        in.val = inl % modlong::MOD;
        return is;
    }
};

// コンビネーション
inline modlong modComb(ll n, ll k) { return modlong(n).comb(k); }
// 階乗
inline modlong modFact(ll n) { return modlong(n).fact(); }

// static変数たち c++17ならinlineでかけるのでclassの中に入れられる(https://ja.cppreference.com/w/cpp/language/static)
ll *modlong::invs  = new ll[MAX+1];
ll *modlong::facts = new ll[MAX+1];
ll *modlong::finvs = new ll[MAX+1];

ll modlong::MOD = (ll)1e9 + 7;

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


using P = pair<modlong, modlong>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    RerootingTree<P> rrt(
        n, 
        [](P a, P b) { a.fi += b.fi; a.se *= b.se * a.fi.comb(b.fi); return a; },
        [](P a, P par) { a.fi++; return a; },
        P{0, 1}
    );
    for (int i=0, ai, bi; i<n-1; i++) {
        cin >> ai >> bi;
        ai--; bi--;
        rrt.add_edge(ai, bi);
    }
    for (auto &ri:rrt()) cout << ri.se << '\n';
    return 0;
}