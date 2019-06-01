#include <cstdio>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#define mod (long)(1e9 + 7)
#define INF (long)1e15
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

// アルファベット順

//// C

//nC2 O(1)
long comb2(long n) { return n * (n - 1) / 2; }
// nCk O(max(n, k))
long comb(long n, long k) {
    if (n < k || k < 0) return 0;
    if (k == 0 || n == k) return 1;
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

//// D

// 二部グラフ判定
vector<int> G[MAX_N]; // 隣接する頂点のリスト
int color[MAX_N] = {0}; // 各ノードの色 1or-1
int each[2] = {0}; // 各色のノードが何個ずつあるか
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

// 各点への最短経路 dijkstra
long d[MAX_N];  //頂点kから各点への距離
int n; 
void dijkstra(vector<P> G[], int k) { //Gは隣接行列 G[i][j].firstが距離, secondが向かう頂点名, kはスタートする頂点
    fill(d, d+n, INF); d[k] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, k));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int now = p.second;
        if (d[now] < p.first) continue;
        for (size_t j=0; j<G[now].size(); j++) {
            int to = G[now][j].second; long newd = G[now][j].first + d[now];
            if (d[to] > newd) {
                d[to] = newd;
                que.push(P(d[to], to));
            }
        }
    }
}

//// G

// 最大公約数
int gcd(int a, int b) {
    if (a > b) {
        int buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b%a);
}

//// L

// 最小公倍数
ll lcm(ll N, ll M) {
    if (N<M) return lcm(M,N);
    ll product=N*M, buf;
    while(M != 0) {
        buf = N;
        N = M;
        M = buf%M;
    }
    return product/N;
}

// LIC 最長部分増加列
int arr[n];
void lic(int n) {
    int dp[n];
    fill(dp, dp+n, INF);
    for (int i=0; i<n; i++) {
        *lower_bound(dp, dp + n, arr[i]) = arr[i]; // dp[lower_bound(dp, dp+N, arr[i])]と同じ
    } // 等号もありならupper
    printf("%ld\n", lower_bound(dp, dp + n, INF) - dp);
}

//// O

// 構造体の演算子実装例
struct point {
    int x;
    int y;
    void operator = (const point& p) {
        x = p.x;
        y = p.y;
    }
};
struct point operator + (const point& p, const int dp[2]) {
    point result;
    result.x = p.x+dp[0]; result.y = p.y+dp[1];
    return result;
}
bool operator == (const point& p, const point& q) {
    return p.x == q.x && p.y == q.y;
}


//// P

// 分割数 sum個のものをn個以下のグループに分ける方法
// ex) sum=4,n=3なら 4=1+1+2=1+3=2+2=4で4通り
int partition(int n, int sum) {
    int dp[n + 1][sum + 1];
    fill(dp[0], dp[n+1], 0);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = (dp[i - 1][j] + (j - i >= 0 ? dp[i][j - i] : 0)) % mod;
        }
    }
    return dp[n][sum];
}

// べき乗 powのint高速化ver
long powi(int x, int n) {
    if (n <= 0) return 1;
    else {
        long xn = powi(x, n/2);
        if (n%2 == 0) return xn*xn;
        else return xn*xn*x;
    }
}

// 素数判定 2からfor分で回して行く powpはどこまでやるか エラトステネスの篩
bool primes[1000]; //最初全部trueにしておく
bool IsPrime(long num, long powp) {
    if (primes[num]) {
        for (long i = 2 * num; i <= powp; i += num)
            primes[i] = false;
    }
    return primes[num];
}

//// U

// Union-Find木 木の統合と同じ木に属すかの確認が可能 分割は不可
// size付きver
struct uftree {
    int par[MAX_N], rank[MAX_N], size[MAX_N];
    uftree(int N) {
        for (int i = 0; i < N; i++) {
            par[i]  = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r         = root(par[x]);
            size[x]       = size[par[x]];
            return par[x] = r;
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y])
            par[y] = x;
        else {
            par[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
        size[x] += size[y];
        size[y] = size[x];
    }
    int getsize(int x) {
        root(x);
        return size[x];
    }
    bool same(int x, int y) { return root(x) == root(y); }
};
// 重み付きver
struct uftree_w {
    int par[MAX_N], rank[MAX_N], w_dif[MAX_N]; //w_difは親との重みの差
    uftree_w(int N) {
        for (int i=0; i<N; i++) {
            par[i] = i;
            rank[i] = 0;
            w_dif[i] = 0;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            w_dif[x] += w_dif[par[x]];
            return par[x] = r;
        }
    }
    int weight(int x) {
        root(x); //経路圧縮
        return w_dif[x];
    }
    bool unite(int x, int y, int d) {
        d += weight(x) - weight(y); //根っこ同士をつなぐので
        x = root(x);
        y = root(y);
        if (x == y) return d == 0;
        if (rank[x] > rank[y]) {
            par[y] = x;
            w_dif[y] = d;
        } else {
            par[x] = y;
            w_dif[x] = -d;
            if (rank[x] == rank[y]) rank[y]++;
        }
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};
