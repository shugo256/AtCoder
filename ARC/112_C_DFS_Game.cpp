#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

std::vector<int> G[100010];

int dfs(int i, std::vector<int> &childs) {
    std::vector<int> oddScores;
    int evenPlus = 0, evenMinus = 0;
    for (auto &g:G[i]) {
        int score = dfs(g, childs);
        childs[i] += childs[g];
        if (childs[g] % 2 == 0) {
            if (score > 0) evenPlus += score;
            else evenMinus += score;
        } else {
            oddScores.push_back(score);
        }
    }
    bool me = true;
    int ans = evenMinus;
    sort(oddScores.begin(), oddScores.end());
    oddScores.push_back(evenPlus);
    for (auto &score: oddScores) {
        if (me) ans += score;
        else ans -= score;
        me = !me;
    }
    // std::cerr << i << ' ' << ans + 1 << ' ' << childs[i] << std::endl;
    return ans + 1; // + 1 は頂点iのコイン分
}

int main() {
    int n;
    std::cin >> n;
    for (int i=1, pi; i<n; i++) {
        std::cin >> pi;
        pi--;
        G[pi].push_back(i);
    }
    // score[i]: 頂点iのコインを取った人がそこを根とする部分きで相手に付ける差
    std::vector<int> childs(n, 1);
    int dif = dfs(0, childs);
    std::cout << (n + dif) / 2 << '\n';
    return 0;
}