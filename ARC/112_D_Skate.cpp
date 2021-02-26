#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

using namespace std;

struct uftree {
    int n, *par, *rank, *size;
    uftree(int N) : n(N) {
        par = new int[(size_t)N];
        rank = new int[(size_t)N];
        size = new int[(size_t)N];
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
    int get_size(int x) {
        root(x);
        return size[x];
    }
    bool same(int x, int y) { return root(x) == root(y); }

    // 集合の数をカウントする関数
    // 1..nのつもりでやってる場合も0をカウントしちゃうので注意
    int count_sets() {
        int cnt = 0;
        bool used[n];
        fill(used, used+n, false);
        for (int i=0; i<n; i++) {
            if (used[root(i)]) continue;
            cnt++;
            used[root(i)] = true;
        }
        return cnt;
    }
};


int main() {
    int h, w;
    std::cin >> h >> w;
    uftree uft(h + w);
    uft.unite(0, h);
    uft.unite(0, h + w - 1);
    uft.unite(h - 1, h);
    uft.unite(h - 1, h + w - 1);
    std::vector S(h, std::string());
    for (int i=0; i<h; i++) {
        std::cin >> S[i];
        for (int j=0; j<w; j++) {
            if (S[i][j] == '#') {
                uft.unite(i, h + j);
            }
        }
    }
    std::set<int> tate, yoko, naka;
    for (int i=0; i<h; i++) {
        tate.insert(uft.root(i));
    }
    for (int i=0; i<w; i++) {
        yoko.insert(uft.root(i+h));
    }
    std::cout << std::min({tate.size() - 1, yoko.size() - 1}) << '\n';
    return 0;
}