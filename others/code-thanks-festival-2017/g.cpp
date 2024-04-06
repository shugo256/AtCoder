#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//  暑休みの宿題

// 最大独立集合 O((1.381^n) * n)?
#include <numeric>
#define MAX 40
int n, m;
vector<int> G[MAX];   // 隣接リスト
int rankid[MAX];      // 次数(=G[i].size())が大きい順に頂点を並べた配列 関数呼び出し時に構築
bool used[MAX] = {0};
int maximum_independent_set(int i=0) {
    int a = 0, b = 0, c = 0;
    if (i == 0) {
        iota(rankid, rankid+n, 0);
        auto cmp = [&](int l, int r) {
            return G[l].size() > G[r].size();
        };
        sort(rankid, rankid+n, cmp);

        // 次数1の頂点は最初に使ってしまう その分のカウントをaに入れる
        for (int j=0; j<n; j++) {
            int r = rankid[j];
            //cerr << j << ' ' << r << '\n';
            if (G[r].size() > 1 || used[r]) continue;
            if (G[r].size() == 0) break;
            a++;
            //cerr << r << '\n';
            used[r] = true;
            used[G[r][0]] = true;
        }
        //cerr << a << '\n';
    }
    int r = rankid[i];
    if (i == n) return 0;
    else if (G[r].size() == 0) return n - i;
    if (i > 0) b = maximum_independent_set(i + 1); // bはiを使わなかった場合
    c = 0; // cは使った場合
    if (!used[r]) {
        used[r] = true;
        vector<int> changed;
        for (auto g:G[r]) {
            if (used[g]) continue;
            used[g] = true;
            changed.push_back(g);
        }
        c = maximum_independent_set(i + 1) + 1;
        used[r] = false;
        for (auto g:changed) used[g] = false;
    }
    //cerr << a << ' ' << b << ' ' << c << '\n';
    return a + max(b, c);
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << maximum_independent_set() << '\n';
    return 0;
}