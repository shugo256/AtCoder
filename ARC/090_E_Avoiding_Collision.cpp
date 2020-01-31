#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <functional>

using ll = long long;

using namespace std;

#define MAX_N 1000000
#define INF ((ll)1e18)

using P = pair<ll, int>;
#define fi first
#define se second

// 各点への最短経路 dijkstra
ll ds[MAX_N], dt[MAX_N];  //頂点kから各点への距離
vector<P> G[MAX_N]; //隣接行列

void dijkstra(int k, int n, ll *d) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d, d+n, INF); d[k] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (auto g:G[now]) {
            int to = g.second;
            ll newd = g.first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

#include <cassert>
#define MOD (long)(1e9 + 7)
#define MAX 2  // 階乗をいくつまで計算するか

class modlong {
    long val;
    static const long mod = MOD;
    static long *invs, *facts, *finvs;

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
    // 初期化 値を引数に与えなかった場合はval=0としておく
    modlong(long init = 0) : val(init) {
        static bool call_once = initModlong(); // static変数の性質により一度だけ呼ばれる
        assert(call_once); // unusedの回避
        if (val < 0 || val >= mod) val %= mod;
        if (val < 0) val += mod;   // 0以上であることを保証
    }

    // longへのキャスト operator long()で定義すると modlong +
    // longとかができなくなる
    inline long tol() { return this->val; }

    // 代入
    void operator=(const modlong &r) { this->val = r.val; }
    void operator=(const long &r) { *this = modlong(r); }

    // 足し算; 符号反転; 引き算
    modlong operator+(const modlong &r) {
        long ans = this->val + r.val;
        if (ans >= mod) ans -= mod;
        return modlong(ans);
    }
    modlong operator-() {
        long ans = mod - this->val;
        return modlong(ans);
    }
    modlong operator-(const modlong &r) {
        modlong rr = r;
        return *this + (-rr);
    }

    //かけ算; 逆元; わり算
    modlong operator*(const modlong &r) {
        long ans = this->val * r.val;
        return modlong(ans);
    }
    modlong inv() {
        assert(*this != 0);
        if (*this == 1) return modlong(1);

        modlong p, q = *this, m(0), n(1), r, c;
        p.val = mod;  // p=modとかくとp.val=mod%mod=0となってしまう
        while (q > MAX) {
            r = p.val % q.val;  // r.val=p.val % q.val
                                // とかくよりもこのほうが代入時に%modされるので安全
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n * invs[q.val];
    }
    modlong operator/(const modlong &r) { return *this * modlong(r).inv(); }

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
        const long n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return modlong(facts[n]) * finvs[k] * finvs[n - k];
    }

    // 階乗
    modlong fact() { 
        assert(this->val <= MAX);
        return modlong(facts[this->val]);
    }

    friend bool operator<(const modlong &l, const modlong &r);
    friend bool operator>(const modlong &l, const modlong &r);
    friend bool operator==(const modlong &l, const modlong &r);
    friend bool operator!=(const modlong &l, const modlong &r);
    friend bool operator<=(const modlong &l, const modlong &r);
    friend bool operator>=(const modlong &l, const modlong &r);
    friend ostream &operator<<(ostream &os, const modlong &out);
    friend istream &operator>>(istream &is, modlong &out);
};

//比較
bool operator<(const modlong &l, const modlong &r) { return l.val < r.val; }
bool operator>(const modlong &l, const modlong &r) { return l.val > r.val; }
bool operator==(const modlong &l, const modlong &r) { return l.val == r.val; }
bool operator!=(const modlong &l, const modlong &r) { return !(l == r); }
bool operator<=(const modlong &l, const modlong &r) { return !(l > r); }
bool operator>=(const modlong &l, const modlong &r) { return !(l < r); }

// cout、cerr、cin用の演算子たち
ostream &operator<<(ostream &os, const modlong &out) {
    os << out.val;
    return os;
}
istream &operator>>(istream &is, modlong &in) {
    long inl;
    is >> inl;
    in.val = inl % MOD;
    return is;
}

// コンビネーション
inline modlong modComb(long n, long k) { return modlong(n).comb(k); }
// 階乗
inline modlong modFact(long n) { return modlong(n).fact(); }

// static変数たち
long *modlong::invs  = new long[MAX+1],
     *modlong::facts = new long[MAX+1],
     *modlong::finvs = new long[MAX+1];



struct edge { int u, v, ui, vi; };

edge E[MAX_N];

modlong cnts[MAX_N] = {0}, cntt[MAX_N] = {0};
bool visited[MAX_N] = {0};

void dfs(int k, ll *d, modlong *cnt) {
    fill(begin(visited), end(visited), false);
    visited[k] = true;
    priority_queue<int, vector<int>, function<bool(int, int)>> que([&d](int l, int r) {
        return d[l] > d[r];
    });
    que.push(k);
    cnt[k] = 1;
    while (!que.empty()) {
        int i = que.top(); que.pop();
        for (auto g:G[i]) {
            int to = g.second;
            ll newd = g.first + d[i];
            if (d[to] == newd) {
                cnt[to] += cnt[i];
                if (!visited[to]) que.push(to);
                visited[to] = true;
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    for (int i=0, u, v, d; i<m; i++) {
        cin >> u >> v >> d;
        u--; v--;
        E[i] = {u, v, (int)G[u].size(), (int)G[v].size()};
        G[u].push_back({d, v});
        G[v].push_back({d, u});
    }
    dijkstra(s, n, ds);
    dijkstra(t, n, dt);
    vector<edge> mids;
    for (int i=0; i<m; i++) {
        if (ds[E[i].u] > ds[E[i].v]) {
            swap(E[i].u, E[i].v);
            swap(E[i].ui, E[i].vi);
        }
        if (ds[E[i].u] + dt[E[i].u] == ds[t] && ds[E[i].v] + dt[E[i].v] == ds[t] && ds[E[i].u] < dt[E[i].u] && ds[E[i].v] > dt[E[i].v] && ds[E[i].v] == ds[E[i].u] + G[E[i].u][E[i].ui].fi)
            mids.push_back(E[i]);
    }
    for (int i=0; i<n; i++)
        if (2 * ds[i] == ds[t] && 2 * dt[i] == ds[t]) mids.push_back({i, i, 0, 0});
    dfs(s, ds, cnts);
    dfs(t, dt, cntt);
    // for (int i=0; i<n; i++) cerr << ds[i] << ' ' << dt[i] << '\n';
    modlong sum = 0, ans = 0;
    // for (auto &m:mids) cerr << m.u << ' ' << m.v << ' ' << cnts[m.u] << ' ' << cntt[m.v] << '\n';
    for (auto &m:mids) sum += cnts[m.u] * cntt[m.v];
    for (auto &m:mids) ans += cnts[m.u] * cntt[m.v] * (sum - cnts[m.u] * cntt[m.v]);
    cout << ans << '\n';
    return 0;
}